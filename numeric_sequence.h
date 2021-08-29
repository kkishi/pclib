#include "pow.h"

template <typename T>
T ArithmeticProgressionSum(T a1, T d, T n) {
  T an = a1 + d * (n - 1);
  return n * (a1 + an) / 2;
}

template <typename T>
T GeometricProgressionSum(T a1, T r, T n) {
  return a1 * (1 - Pow(r, n)) / (1 - r);
}
