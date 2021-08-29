#include "numeric_sequence.h"

#include "gtest/gtest.h"

TEST(numeric_sequence, arithmetic_progression) {
  EXPECT_EQ(ArithmeticProgressionSum(2, 3, 5), 40);
  EXPECT_EQ(ArithmeticProgressionSum(3, -1, 5), 5);
}

TEST(numeric_sequence, geometric_progression) {
  EXPECT_EQ(GeometricProgressionSum(2, 5, 4), 312);
}
