#include <algorithm>
#include <iostream>

using i128 = __int128_t;

i128 stoi128(const std::string_view s) {
  if (s[0] == '-') return -stoi128(s.substr(1));
  i128 x = 0;
  for (std::size_t i = 0; i < s.size(); ++i) {
    (x *= 10) += s[i] - '0';
  }
  return x;
}

std::istream& operator>>(std::istream& is, i128& x) {
  std::string s;
  is >> s;
  x = stoi128(s);
  return is;
}

std::string to_string(i128 x) {
  if (x == 0) return "0";
  if (x < 0) return '-' + to_string(-x);
  std::string s;
  for (; x; x /= 10) {
    s += '0' + x % 10;
  }
  std::reverse(s.begin(), s.end());
  return s;
}

std::ostream& operator<<(std::ostream& os, i128 x) {
  os << to_string(x);
  return os;
}
