#include <cstdint>
#include <map>

#include "dassert.h"

class RunLengthSet : public std::map<int64_t, int64_t> {
 public:
  void Insert(int64_t val, int64_t cnt) {
    size_ += cnt;
    sum_ += val * cnt;
    auto&& [it, ok] = insert({val, cnt});
    if (!ok) it->second += cnt;
  }

  void Erase(std::map<int64_t, int64_t>::iterator it) {
    dassert(it != end());
    size_ -= it->second;
    sum_ -= it->first * it->second;
    erase(it);
  }

  int64_t Size() const { return size_; }
  int64_t Sum() const { return sum_; }

 private:
  int64_t size_ = 0;
  int64_t sum_ = 0;
};
