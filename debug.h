#ifndef DEBUG_H_
#define DEBUG_H_

#include <functional>
#include <iostream>

#include "type_traits.h"

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

#endif  // DEBUG_H_
