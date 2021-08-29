template <typename T>
T ArithmeticProgressionSum(T a1, T d, T n) {
  T an = a1 + d * (n - 1);
  return n * (a1 + an) / 2;
}
