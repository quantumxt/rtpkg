// Copyright 2021 Photon
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <memory>
#include <random>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int16.hpp"

#include "cpp_pubsub/helper.hpp"
#include "rtpkg_msg/msg/rndnum.hpp"

using namespace std::chrono_literals;        // For timer

class SubscriberCpp : public rclcpp::Node
{
public:
  SubscriberCpp()
  : Node("nodesub_cpp")
  {
    // Subscriber(s)
    subscriptionCPP_ = this->create_subscription<std_msgs::msg::String>(
      "topic_cpp", 10, std::bind(&SubscriberCpp::topic_cpp_callback, this, std::placeholders::_1));
    subscriptionPY_ = this->create_subscription<std_msgs::msg::String>(
      "topic_py", 10, std::bind(&SubscriberCpp::topic_py_callback, this, std::placeholders::_1));

    // Publisher(s)
    publisher_ = this->create_publisher<rtpkg_msg::msg::Rndnum>("rnd_num", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&SubscriberCpp::rndno_callback, this));
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriptionCPP_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriptionPY_;

  rclcpp::Publisher<rtpkg_msg::msg::Rndnum>::SharedPtr publisher_;

  rclcpp::TimerBase::SharedPtr timer_;

  rtpkg rnum;   // Custom topic

  void topic_cpp_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Get C++ dat: '%s'", msg->data.c_str());
  }

  void topic_py_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Get Python dat: '%s'", msg->data.c_str());
  }

  void rndno_callback()
  {
    rtpkg_msg::msg::Rndnum rndnum = rtpkg_msg::msg::Rndnum();
    int n{rnum.getRand(1, 10000)};
    rndnum.data = n;
    rndnum.data_min = rnum.getMin();
    rndnum.data_max = rnum.getMax();
    rndnum.is_prime = rnum.checkPrime(n);
    rndnum.prime_ratio = rnum.getPrimeRatio();
    RCLCPP_INFO(this->get_logger(), "RAND NUM: '%i'", rndnum.data);
    publisher_->publish(rndnum);
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SubscriberCpp>());
  rclcpp::shutdown();
  return 0;
}
