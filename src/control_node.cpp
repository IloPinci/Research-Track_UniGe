#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "a2_controller/msg/obstacle_info.hpp"
#include "a2_controller/srv/set_safety_threshold.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class ControllerNode : public rclcpp::Node {
public:
    ControllerNode() : Node("control_node"), 
                       safety_threshold_(0.5), 
                       safety_active_(false),
                       backup_counter_(0),
                       max_backup_iterations_(10) {  // ~1 second of backup at 10Hz

        sub_input_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel_input", 10, 
            std::bind(&ControllerNode::input_callback, this, _1));

        sub_scan_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10, 
            std::bind(&ControllerNode::scan_callback, this, _1));

        pub_cmd_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        pub_info_ = this->create_publisher<a2_controller::msg::ObstacleInfo>("/obstacle_info", 10);

        srv_threshold_ = this->create_service<a2_controller::srv::SetSafetyThreshold>(
            "set_safety_threshold", 
            std::bind(&ControllerNode::set_threshold_callback, this, _1, _2));
        
        RCLCPP_INFO(this->get_logger(), "Controller Ready. Threshold: %.2f", safety_threshold_);
    }

private:
    void input_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        if (!safety_active_) {
            pub_cmd_->publish(*msg);
        }
    }

    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        float min_dist = 100.0;
        int index = -1;

        // Find the closest point in the laser scan
        for (size_t i = 0; i < msg->ranges.size(); ++i) {
            if (msg->ranges[i] < min_dist && msg->ranges[i] > msg->range_min) {
                min_dist = msg->ranges[i];
                index = i;
            }
        }

        // Handle backup behavior
        if (safety_active_ && backup_counter_ > 0) {
            // Continue backing up
            auto reverse_cmd = geometry_msgs::msg::Twist();
            reverse_cmd.linear.x = -0.3;
            pub_cmd_->publish(reverse_cmd);
            backup_counter_--;
            
            if (backup_counter_ == 0) {
                // Stop after backup is complete
                auto stop_cmd = geometry_msgs::msg::Twist();
                stop_cmd.linear.x = 0.0;
                pub_cmd_->publish(stop_cmd);
                safety_active_ = false;
            }
        } 
        else if (min_dist < safety_threshold_ && !safety_active_) {
            // Obstacle detected, start backup
            safety_active_ = true;
            backup_counter_ = max_backup_iterations_;
            
            auto reverse_cmd = geometry_msgs::msg::Twist();
            reverse_cmd.linear.x = -0.3;
            pub_cmd_->publish(reverse_cmd);
            
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000, 
                "\033[1;33mOBSTACLE! Backing up.\033[0m");
        }

        // Publish obstacle info
        auto info = a2_controller::msg::ObstacleInfo();
        info.min_distance = min_dist;
        info.current_threshold = safety_threshold_;
        
        size_t mid = msg->ranges.size() / 2;
        if (index > (int)mid + 50) info.direction = "Left";
        else if (index < (int)mid - 50) info.direction = "Right";
        else info.direction = "Front";
        
        pub_info_->publish(info);
    }

    void set_threshold_callback(
        const std::shared_ptr<a2_controller::srv::SetSafetyThreshold::Request> request,
        std::shared_ptr<a2_controller::srv::SetSafetyThreshold::Response> response) 
    {
        safety_threshold_ = request->new_threshold;
        response->success = true;
        RCLCPP_INFO(this->get_logger(), "Threshold updated to %.2f", safety_threshold_);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub_input_;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_scan_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_;
    rclcpp::Publisher<a2_controller::msg::ObstacleInfo>::SharedPtr pub_info_;
    rclcpp::Service<a2_controller::srv::SetSafetyThreshold>::SharedPtr srv_threshold_;

    float safety_threshold_;
    bool safety_active_;
    int backup_counter_;
    int max_backup_iterations_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ControllerNode>());
    rclcpp::shutdown();
    return 0;
}