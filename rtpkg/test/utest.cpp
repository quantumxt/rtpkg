#include "rtpkg/helper.hpp"
#include <gtest/gtest.h>

rtpkg test_rtpkg;   // Create object

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
  for(int j{0};j>-20000;--j)
    ASSERT_FALSE(test_rtpkg.checkPrime(j));
}

TEST(TestCount, PositiveNos)
{
  EXPECT_EQ(0, test_rtpkg.getCount());
  for(int j{0};j<100;++j)
    test_rtpkg.getRand(1,200);
  EXPECT_EQ(100, test_rtpkg.getCount());
  for(int j{0};j<100000;++j)
    test_rtpkg.getRand(100,5000);
  EXPECT_EQ(100100, test_rtpkg.getCount());
  for(int j{0};j<100000;++j)
    test_rtpkg.getRand(-70,10000);
  EXPECT_EQ(200100, test_rtpkg.getCount());
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
