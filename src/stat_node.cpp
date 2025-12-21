#include <deque>
#include <numeric>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "a2_controller/srv/get_velocity_stats.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class StatsNode : public rclcpp::Node {
// constructor
public:
    StatsNode() : Node("stats_node") {
        // listens to what the control node is pushing (for the movement)
        sub_vel_ = this->create_subscription<geometry_msgs::msg::Twist>("/cmd_vel", 10, std::bind(&StatsNode::vel_callback, this, _1));

        // creates an endpoint and waits for user requests. when it gets it will run the function get_...
        srv_stats_ = this->create_service<a2_controller::srv::GetVelocityStats>("get_velocity_stats", std::bind(&StatsNode::get_stats_callback, this, _1, _2));
    }



private:

    // implement a fifo queue
    void vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        // we store only 5 values. if more than 5 we pop
        if (history_.size() >= 5) {
            history_.pop_front();
        }
        history_.push_back(msg->linear.x);

        // same for angular
        if(history_a.size() >= 5){
            history_a.pop_front();
        }
        history_a.push_back(msg->angular.z);    // it is z bc we are calc the angular velocity wrt to the z axis
    }


    void get_stats_callback(
        const std::shared_ptr<a2_controller::srv::GetVelocityStats::Request>,std::shared_ptr<a2_controller::srv::GetVelocityStats::Response> res) 
    {
        if (history_.empty()) {
            res->avg_linear_vel = 0.0;
        }
        else{
            // calc the avg for linear
            float sum = std::accumulate(history_.begin(), history_.end(), 0.0);
            res->avg_linear_vel = sum / history_.size();
        }

        if(history_a.empty()){
            res->avg_angular_vel = 0.0;
            return;
        }
        else{
              // angular
            float sum_a = std::accumulate(history_a.begin(), history_a.end(), 0.0);
            res->avg_angular_vel = sum_a / history_a.size(); 
        }
        
        RCLCPP_INFO(this->get_logger(), "Stats - Linear: %.2f, Angular: %.2f", res->avg_linear_vel, res->avg_angular_vel);
    }

    // variables
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub_vel_;
    rclcpp::Service<a2_controller::srv::GetVelocityStats>::SharedPtr srv_stats_;
    std::deque<float> history_;
    std::deque<float> history_a;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StatsNode>());
    rclcpp::shutdown();
    return 0;
}