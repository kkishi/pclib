template <typename T>
T Gcd(T a, T b) {
  if (a > b) {
    return Gcd(b, a);
  }
  T m = b % a;
  if (m == 0) {
    return a;
  }
  return Gcd(m, a);
}
