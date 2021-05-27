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

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "rtpkg/helper.hpp"

rtpkg test_rtpkg;   // Create rtpkg object

TEST_CASE("TestCheckPrime", "[numbers]")
{
  REQUIRE(test_rtpkg.checkPrime(1) == 0);
  REQUIRE(test_rtpkg.checkPrime(7) == 1);
  REQUIRE(test_rtpkg.checkPrime(4909) == 1);
  REQUIRE(test_rtpkg.checkPrime(6576) == 0);
  REQUIRE(test_rtpkg.checkPrime(8583) == 0);
  for (int j{0}; j > -20000; --j) {
    REQUIRE(test_rtpkg.checkPrime(j) == 0);
  }
}

TEST_CASE("TestCount", "[PositiveNos]")
{
  REQUIRE(test_rtpkg.getCount() == 0);
  for (int j{0}; j < 100; ++j) {
    test_rtpkg.getRand(1, 200);
  }
  REQUIRE(test_rtpkg.getCount() == 100);
  for (int j{0}; j < 100000; ++j) {
    test_rtpkg.getRand(100, 5000);
  }
  REQUIRE(test_rtpkg.getCount() == 100100);
  for (int j{0}; j < 100000; ++j) {
    test_rtpkg.getRand(-70, 10000);
  }
  REQUIRE(test_rtpkg.getCount() == 200100);
}
