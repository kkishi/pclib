template <typename T>
bool Setmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
