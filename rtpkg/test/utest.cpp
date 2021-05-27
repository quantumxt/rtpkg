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

#include <gtest/gtest.h>
#include "rtpkg/helper.hpp"

rtpkg test_rtpkg;   // Create rtpkg object

TEST(TestCheckPrime, PositiveNos)
{
  EXPECT_FALSE(test_rtpkg.checkPrime(1));
  EXPECT_TRUE(test_rtpkg.checkPrime(7));
  EXPECT_TRUE(test_rtpkg.checkPrime(4909));
  EXPECT_FALSE(test_rtpkg.checkPrime(6576));
  EXPECT_FALSE(test_rtpkg.checkPrime(8583));
}

TEST(TestCheckPrime, ZeroNegativeNos)
{
  for (int j{0}; j > -20000; --j) {
    ASSERT_FALSE(test_rtpkg.checkPrime(j));
  }
}

TEST(TestCount, PositiveNos)
{
  EXPECT_EQ(0, test_rtpkg.getCount());
  for (int j{0}; j < 100; ++j) {
    test_rtpkg.getRand(1, 200);
  }
  EXPECT_EQ(100, test_rtpkg.getCount());
  for (int j{0}; j < 100000; ++j) {
    test_rtpkg.getRand(100, 5000);
  }
  EXPECT_EQ(100100, test_rtpkg.getCount());
  for (int j{0}; j < 100000; ++j) {
    test_rtpkg.getRand(-70, 10000);
  }
  EXPECT_EQ(200100, test_rtpkg.getCount());
}

// Run all the tests that were declared with TEST()
int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
