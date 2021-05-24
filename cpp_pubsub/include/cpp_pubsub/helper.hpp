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

#ifndef CPP_PUBSUB__HELPER_HPP_
#define CPP_PUBSUB__HELPER_HPP_

#include <random>

class rtpkg
{
public:
  rtpkg();
  ~rtpkg();
  int getRand(int minD, int maxD);
  bool checkPrime(int n);
  int getMin();
  int getMax();

private:
  int numMin{10000};
  int numMax{-1000};
  void setMin(int & mn);
  void setMax(int & mx);
};

#endif    // CPP_PUBSUB__HELPER_HPP_
