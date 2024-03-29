#ifndef MACROS_H_
#define MACROS_H_

#include <algorithm>
#include <bitset>
#include <limits>
#include <numeric>
#include <queue>
#include <type_traits>
#include <vector>

#define all(x) (x).begin(), (x).end()
#define eb(...) emplace_back(__VA_ARGS__)
#define pb(...) push_back(__VA_ARGS__)

#define dispatch(_1, _2, _3, name, ...) name

#define as_i64(x)                                                          \
  (                                                                        \
      [] {                                                                 \
        static_assert(                                                     \
            std::is_integral<                                              \
                typename std::remove_reference<decltype(x)>::type>::value, \
            "rep macro supports std integral types only");                 \
      },                                                                   \
      static_cast<int64_t>(x))

#define rep3(i, a, b) for (int64_t i = as_i64(a); i < as_i64(b); ++i)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(_loop_variable_, n)
#define rep(...) dispatch(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep3(i, a, b) for (int64_t i = as_i64(b) - 1; i >= as_i64(a); --i)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep1(n) rrep2(_loop_variable_, n)
#define rrep(...) dispatch(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define each3(k, v, c) for (auto&& [k, v] : c)
#define each2(e, c) for (auto&& e : c)
#define each(...) dispatch(__VA_ARGS__, each3, each2)(__VA_ARGS__)

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
auto max(const T& v) {
  return *std::max_element(v.begin(), v.end());
}

template <typename T>
auto min(const T& v) {
  return *std::min_element(v.begin(), v.end());
}

template <typename T>
int64_t sz(const T& v) {
  return std::size(v);
}

template <typename T>
int64_t popcount(T i) {
  return std::bitset<std::numeric_limits<T>::digits>(i).count();
}

template <typename T>
bool hasbit(T s, int i) {
  return std::bitset<std::numeric_limits<T>::digits>(s)[i];
}

template <typename T, typename U>
auto div_floor(T n, U d) {
  if (d < 0) {
    n = -n;
    d = -d;
  }
  if (n < 0) {
    return -((-n + d - 1) / d);
  }
  return n / d;
};

template <typename T, typename U>
auto div_ceil(T n, U d) {
  if (d < 0) {
    n = -n;
    d = -d;
  }
  if (n < 0) {
    return -(-n / d);
  }
  return (n + d - 1) / d;
}

template <typename T>
bool even(T x) {
  return x % 2 == 0;
}

std::array<std::pair<int64_t, int64_t>, 4> adjacent(int64_t i, int64_t j) {
  return {{{i + 1, j}, {i, j + 1}, {i - 1, j}, {i, j - 1}}};
}

bool inside(int64_t i, int64_t j, int64_t I, int64_t J) {
  return 0 <= i && i < I && 0 <= j && j < J;
}

template <typename T>
void sort(T& v) {
  return std::sort(v.begin(), v.end());
}

template <typename T, typename Compare>
void sort(T& v, Compare comp) {
  return std::sort(v.begin(), v.end(), comp);
}

template <typename T>
void reverse(T& v) {
  return std::reverse(v.begin(), v.end());
}

bool islower(char c) { return 'a' <= c && c <= 'z'; }
bool isupper(char c) { return 'A' <= c && c <= 'Z'; }

template <typename T>
typename T::value_type accumulate(const T& v) {
  return std::accumulate(v.begin(), v.end(), typename T::value_type());
}

using i64 = int64_t;
using i32 = int32_t;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

#endif  // MACROS_H_
