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

#ifndef RTPKG__HELPER_HPP_
#define RTPKG__HELPER_HPP_

#include <random>

class rtpkg
{
public:
  rtpkg();
  ~rtpkg();

  /**
  * @brief Function to generate a random number.
  * @param minD - Minimum number value to be generated.
  * @param maxD - Maximum number value to be generated.
  * @return The generated random number.
  */
  int getRand(int minD, int maxD);

  /**
  * @brief Function to check whether the input number is a prime number.
  * @param n - Input number to be check.
  * @return True if the number supplied is a prime number.
  */
  bool checkPrime(int n);

  /**
  * @brief Function to get the ratio of the number of prime number generated over
  * the total number of random number generated. 
  * @return Float value of the prime number ratio.
  */
  float getPrimeRatio();

  /**
  * @brief Function to get the total number of random number generated. 
  */
  int getCount();

  /**
  * @brief Function to get the smallest number generated. 
  */
  int getMin();

  /**
  * @brief Function to get the largest number generated. 
  */
  int getMax();

private:
  int numMin{10000};
  int numMax{-1000};
  int totalCount{0};
  int totalPrime{0};
  void setMin(int & mn);
  void setMax(int & mx);
};

#endif    // RTPKG__HELPER_HPP_
