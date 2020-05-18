template <typename T>
T Gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}
