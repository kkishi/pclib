#include <bitset>
#include <functional>
#include <iostream>
#include <queue>
#include <type_traits>
#include <vector>

template <typename T, typename = void>
struct is_dereferenceable : std::false_type {};
template <typename T>
struct is_dereferenceable<T, std::void_t<decltype(*std::declval<T>())>>
    : std::true_type {};

template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))>>
    : std::true_type {};

template <typename T, typename = void>
struct is_applicable : std::false_type {};
template <typename T>
struct is_applicable<T, std::void_t<decltype(std::tuple_size<T>::value)>>
    : std::true_type {};

template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args);
template <typename T>
void debug(const T& v) {
  if constexpr (is_dereferenceable<T>::value) {
    std::cerr << "{";
    if (v) {
      debug(*v);
    } else {
      std::cerr << "nil";
    }
    std::cerr << "}";
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    std::cerr << "{";
    for (auto it = std::begin(v); it != std::end(v); ++it) {
      if (it != std::begin(v)) std::cerr << ", ";
      debug(*it);
    }
    std::cerr << "}";
  } else if constexpr (is_applicable<T>::value) {
    std::cerr << "{";
    std::apply([](const auto&... args) { debug(args...); }, v);
    std::cerr << "}";
  } else {
    std::cerr << v;
  }
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
#define ints(...) rd(int, __VA_ARGS__);
#define strings(...) rd(string, __VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  if constexpr (std::is_same<T, bool>::value) {
    std::cout << (value ? "Yes" : "No");
  } else {
    std::cout << value;
  }
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  write_to_cout(value);
  std::cout << ' ';
  write_to_cout(args...);
}
#define wt(...)                 \
  do {                          \
    write_to_cout(__VA_ARGS__); \
    cout << '\n';               \
  } while (0)

#define all(x) (x).begin(), (x).end()

#define dispatch(_1, _2, _3, name, ...) name

#define as_i64(x)                                                          \
  (                                                                        \
      [] {                                                                 \
        static_assert(                                                     \
            std::is_integral<                                              \
                typename std::remove_reference<decltype(x)>::type>::value, \
            "rep macro supports std integral types only");                 \
      },                                                                   \
      static_cast<std::int64_t>(x))

#define rep3(i, a, b) for (std::int64_t i = as_i64(a); i < as_i64(b); ++i)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(_loop_variable_, n)
#define rep(...) dispatch(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep3(i, a, b) for (std::int64_t i = as_i64(b) - 1; i >= as_i64(a); --i)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep1(n) rrep2(_loop_variable_, n)
#define rrep(...) dispatch(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define each3(k, v, c) for (auto&& [k, v] : c)
#define each2(e, c) for (auto&& e : c)
#define each(...) dispatch(__VA_ARGS__, each3, each2)(__VA_ARGS__)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T, typename U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T, typename U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
bool chmin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
auto max(T a, U b) {
  return a > b ? a : b;
}

template <typename T, typename U>
auto min(T a, U b) {
  return a < b ? a : b;
}

template <typename T>
int sz(const T& v) {
  return v.size();
}

template <typename T>
int popcount(T i) {
  return std::bitset<std::numeric_limits<T>::digits>(i).count();
}

template <typename T>
bool hasbit(T s, int i) {
  return std::bitset<std::numeric_limits<T>::digits>(s)[i];
}

template <typename T, typename U>
auto div_ceil(T n, U d) {
  return (n + d - 1) / d;
}

template <typename T>
bool even(T x) {
  return x % 2 == 0;
}

const std::int64_t big = std::numeric_limits<std::int64_t>::max() / 10;

using i64 = std::int64_t;
using i32 = std::int32_t;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;
