#ifndef DEBUG_H_
#define DEBUG_H_

#include <functional>
#include <iostream>

#include "constants.h"
#include "type_traits.h"

template <typename T, typename... Ts>
void debug(std::ostream& os, const T& value, const Ts&... args);
template <typename T>
void debug(std::ostream& os, const T& v) {
  if constexpr (std::is_same<int64_t, std::decay_t<T>>::value) {
    if (v == big) {
      os << "big";
    } else {
      os << v;
    }
  } else if constexpr (std::is_same<char*, std::decay_t<T>>::value ||
                       std::is_same<std::string, T>::value) {
    os << v;
  } else if constexpr (is_dereferenceable<T>::value) {
    os << "{";
    if (v) {
      debug(os, *v);
    } else {
      os << "nil";
    }
    os << "}";
  } else if constexpr (is_iterable<T>::value) {
    os << "{";
    for (auto it = std::begin(v); it != std::end(v); ++it) {
      if (it != std::begin(v)) os << ", ";
      debug(os, *it);
    }
    os << "}";
  } else if constexpr (is_applicable<T>::value) {
    os << "{";
    std::apply([&os](const auto&... args) { debug(os, args...); }, v);
    os << "}";
  } else {
    os << v;
  }
}
template <typename T, typename... Ts>
void debug(std::ostream& os, const T& value, const Ts&... args) {
  debug(os, value);
  os << ", ";
  debug(os, args...);
}
#if DEBUG
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(std::cerr, __VA_ARGS__);      \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

#endif  // DEBUG_H_
