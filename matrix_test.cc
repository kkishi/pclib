#include "matrix.h"

#include "gtest/gtest.h"
#include "modint.h"

TEST(matrix, mult) {
  Matrix<int, 2, 3> A{{{1, 2, 3}, {4, 5, 6}}};
  Matrix<int, 3, 2> B{{{1, 2}, {3, 4}, {5, 6}}};
  Matrix<int, 2, 2> C = Mult(A, B);
  Matrix<int, 2, 2> D{{{22, 28}, {49, 64}}};
  EXPECT_EQ(C, D);
}

TEST(matrix, add) {
  Matrix<int, 2, 2> A{{{1, 2}, {3, 4}}};
  Matrix<int, 2, 2> B{{{5, 6}, {7, 8}}};
  Matrix<int, 2, 2> C = Plus(A, B);
  Matrix<int, 2, 2> D = {{{6, 8}, {10, 12}}};
  EXPECT_EQ(C, D);
}

TEST(matrix, pow) {
  Matrix<ModInt<>, 2, 2> A{{{1, 1}, {1, 0}}};
  auto B = Pow(A, std::numeric_limits<int64_t>::max());
  EXPECT_EQ(B[0][0], 814278197);
}
