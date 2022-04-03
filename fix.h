#ifndef FIX_H_
#define FIX_H_

#include <functional>

template <class F>
struct FixPoint {
  F f;
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return f(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class F>
FixPoint<std::decay_t<F>> Fix(F&& f) {
  return {std::forward<F>(f)};
}

#endif  // FIX_H_
