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

#include "cpp_pubsub/helper.hpp"

rtpkg::rtpkg() {}

rtpkg::~rtpkg() {}

int rtpkg::getRand(int minD, int maxD)
{
  // Generate random number: https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(minD, maxD);
  int tmpNum{static_cast<int>(dist(mt))};
  if (tmpNum > numMax) {
    setMax(tmpNum);
  }
  if (tmpNum < numMin) {
    setMin(tmpNum);
  }
  return tmpNum;
}

int rtpkg::getMin()
{
  return numMin;
}

int rtpkg::getMax()
{
  return numMax;
}

void rtpkg::setMin(int & mn)
{
  numMin = mn;
}

void rtpkg::setMax(int & mx)
{
  numMax = mx;
}
