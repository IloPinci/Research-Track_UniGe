#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "a2_controller/msg/obstacle_info.hpp"
#include "a2_controller/srv/set_safety_threshold.hpp"

using std::placeholders::_1;    // first arg
using std::placeholders::_2;    // second arg

class ControllerNode : public rclcpp::Node {
// define the constructor
public:
    ControllerNode() : Node("control_node"), safety_threshold_(0.5), safety_active_(false) {

        // for subscribers

        // we create a subscriber that listens for user input. it keeps the 
        // last 10 instances of user inputs. for each input it calls a function
        sub_input_ = this->create_subscription<geometry_msgs::msg::Twist>("/cmd_vel_input", 10, std::bind(&ControllerNode::input_callback, this, _1));

        // another subscriber is created. This one gets messages from the 
        // laser scanner and calls another functiomn for each message that
        // it receives 
        sub_scan_ = this->create_subscription<sensor_msgs::msg::LaserScan>("/scan", 10, std::bind(&ControllerNode::scan_callback, this, _1));




        // for publishers

        // a publisher that sends commands to the 'wheels' of the robot
        pub_cmd_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        
        // a publisher that sends custom messages
        pub_info_ = this->create_publisher<a2_controller::msg::ObstacleInfo>("/obstacle_info", 10);




        // other usages
        // the user can set the safety threshold as he likes. call  a function to do
        srv_threshold_ = this->create_service<a2_controller::srv::SetSafetyThreshold>("set_safety_threshold", std::bind(&ControllerNode::set_threshold_callback, this, _1, _2));
        
        // print log messages
        RCLCPP_INFO(this->get_logger(), "Controller Ready. Threshold: %.2f", safety_threshold_);
    }



private:
    void input_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        // for the velocity that has been given it checks if the robot is 
        // in a safe distance, then passes the command to the robot.
        // if not disregards the input
        if (!safety_active_) {
            pub_cmd_->publish(*msg);
        }
    }



    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        float min_dist = 100.0;
        int index = -1;

        // find the closest point in the laser scan
        for (size_t i = 0; i < msg->ranges.size(); ++i) {
            if (msg->ranges[i] < min_dist && msg->ranges[i] > msg->range_min) {
                min_dist = msg->ranges[i];
                index = i;
            }
        }

        // if an object is closer thatn our safety threshold
        if (min_dist < safety_threshold_) {
            safety_active_ = true;
            
            // create a reverse command
            auto reverse_cmd = geometry_msgs::msg::Twist();
            reverse_cmd.linear.x = -0.3; // backup
            pub_cmd_->publish(reverse_cmd); // overwrite the user command
            
            // just a warning
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "OBSTACLE! Backing up.");
        } else {
            safety_active_ = false;
        }

        // we fill the custom message with the data that we calc
        auto info = a2_controller::msg::ObstacleInfo();
        info.min_distance = min_dist;
        info.current_threshold = safety_threshold_;
        
        // find the direction of the obstacle
        size_t mid = msg->ranges.size() / 2;
        // if the index of the closest object is larger than the middle of the array than the object is on the left of the robot
        if (index > (int)mid + 50) info.direction = "Left"; 
        // if the index of the closest object is smaller than the middle of the array than the object is on the right of the robot
        else if (index < (int)mid - 50) info.direction = "Right";
        // if not then it is on the front
        else info.direction = "Front";
        
        pub_info_->publish(info);
    }

    // updating the threshold
    void set_threshold_callback(const std::shared_ptr<a2_controller::srv::SetSafetyThreshold::Request> request,std::shared_ptr<a2_controller::srv::SetSafetyThreshold::Response> response) 
    {
        safety_threshold_ = request->new_threshold;
        response->success = true;
        RCLCPP_INFO(this->get_logger(), "Threshold updated to %.2f", safety_threshold_);
    }

    // variables
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub_input_;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_scan_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_;
    rclcpp::Publisher<a2_controller::msg::ObstacleInfo>::SharedPtr pub_info_;
    rclcpp::Service<a2_controller::srv::SetSafetyThreshold>::SharedPtr srv_threshold_;

    float safety_threshold_;
    bool safety_active_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);   // init ros2
    rclcpp::spin(std::make_shared<ControllerNode>()); // create the node 
    rclcpp::shutdown();
    return 0;
}