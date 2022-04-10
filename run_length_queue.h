#include <cstdint>
#include <deque>
#include <vector>

class RunLengthQueue : public std::deque<std::pair<int64_t, int64_t>> {
 public:
#define PUSH(Dir, dir)                       \
  void Push##Dir(int64_t val, int64_t cnt) { \
    size_ += cnt;                            \
    if (!empty()) {                          \
      auto& [v, c] = dir();                  \
      if (v == val) {                        \
        c += cnt;                            \
        return;                              \
      }                                      \
    }                                        \
    emplace_##dir(val, cnt);                 \
  }
  PUSH(Back, back)
  PUSH(Front, front)
#undef PUSH

#define POP(Dir, dir)                                              \
  std::vector<std::pair<int64_t, int64_t>> Pop##Dir(int64_t cnt) { \
    std::vector<std::pair<int64_t, int64_t>> ret;                  \
    while (cnt > 0 && !empty()) {                                  \
      auto& [v, c] = dir();                                        \
      int64_t p = std::min(cnt, c);                                \
      ret.emplace_back(v, p);                                      \
      cnt -= p;                                                    \
      c -= p;                                                      \
      size_ -= p;                                                  \
      if (c == 0) pop_##dir();                                     \
    }                                                              \
    return ret;                                                    \
  }
  POP(Back, back)
  POP(Front, front)
#undef POP

  int64_t Size() const { return size_; }

 private:
  int64_t size_ = 0;
};
