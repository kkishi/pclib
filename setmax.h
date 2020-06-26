template <typename T>
bool Setmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
