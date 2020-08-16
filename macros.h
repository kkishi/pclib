#include <functional>
#include <iostream>
#include <queue>
#include <type_traits>
#include <vector>

template <typename T, typename _ = void>
struct is_container : std::false_type {};
template <typename T>
struct is_container<T, std::void_t<decltype(std::declval<T>().begin()),
                                   decltype(std::declval<T>().end())>>
    : std::true_type {};

template <typename T, std::enable_if_t<!is_container<T>::value>* = nullptr>
void debug(const T& value);
template <typename T, std::enable_if_t<is_container<T>::value>* = nullptr>
void debug(const T& c);
template <typename T, typename U>
void debug(const std::pair<T, U>& p);

template <typename T, std::enable_if_t<!is_container<T>::value>* = nullptr>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, std::enable_if_t<is_container<T>::value>* = nullptr>
void debug(const T& c) {
  std::cerr << "{";
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) std::cerr << ", ";
    debug(*it);
  }
  std::cerr << "}";
}
template <typename T, typename U>
void debug(const std::pair<T, U>& p) {
  std::cerr << "{";
  debug(p.first);
  std::cerr << ", ";
  debug(p.second);
  std::cerr << "}";
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  debug(value);
  std::cerr << ", ";
  debug(args...);
}
#if DEBUG
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << '\n';
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define wt(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

#include <boost/hana/functional/fix.hpp>
auto Fix = boost::hana::fix;

using ll = long long;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;
