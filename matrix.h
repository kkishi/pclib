#include <array>
#include <cstdint>

template <typename T, std::size_t N, std::size_t M>
using Matrix = std::array<std::array<T, M>, N>;

template <typename T, std::size_t N, std::size_t M, std::size_t L>
Matrix<T, N, M> Mult(const Matrix<T, N, L>& a, const Matrix<T, L, M>& b) {
  Matrix<T, N, M> c{};
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      for (std::size_t k = 0; k < L; ++k) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return c;
}

template <typename T, std::size_t N, std::size_t M>
Matrix<T, N, M> Plus(const Matrix<T, N, M>& a, const Matrix<T, N, M>& b) {
  Matrix<T, N, M> c{};
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}

template <typename T, std::size_t N>
Matrix<T, N, N> Pow(const Matrix<T, N, N>& x, std::int64_t y) {
  if (y == 0) {
    Matrix<T, N, N> e{};
    for (std::size_t i = 0; i < N; ++i) {
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
