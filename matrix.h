#include <array>

template <typename T, size_t N, size_t M>
using Matrix = std::array<std::array<T, M>, N>;

template <typename T, size_t N, size_t M, size_t L>
Matrix<T, N, M> Mult(const Matrix<T, N, L>& a, const Matrix<T, L, M>& b) {
  Matrix<T, N, M> c{};
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < M; ++j) {
      for (size_t k = 0; k < L; ++k) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return c;
}

template <typename T, size_t N, size_t M>
Matrix<T, N, M> Plus(const Matrix<T, N, M>& a, const Matrix<T, N, M>& b) {
  Matrix<T, N, M> c{};
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < M; ++j) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}

template <typename T, size_t N>
Matrix<T, N, N> Pow(const Matrix<T, N, N>& x, int64_t y) {
  if (y == 0) {
    Matrix<T, N, N> e{};
    for (size_t i = 0; i < N; ++i) {
      e[i][i] = T(1);
    }
    return e;
  }
  if (y % 2 == 0) {
    Matrix<T, N, N> z = Pow(x, y / 2);
    return Mult(z, z);
  }
  return Mult(Pow(x, y - 1), x);
}
