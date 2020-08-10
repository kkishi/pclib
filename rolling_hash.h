#include <cstdint>
#include <functional>

class RollingHash {
 public:
  void Add(int i) {
    const uint64_t base = 100000007;
    hash_ = hash_ * base + i;
  }
  uint64_t hash() const { return hash_; }
  bool operator==(const RollingHash& h) const { return hash_ == h.hash_; }

 private:
  uint64_t hash_ = 0;
};

namespace std {
template <>
class hash<RollingHash> {
 public:
  size_t operator()(const RollingHash& h) const {
    return hash<uint64_t>()(h.hash());
  }
};
}  // namespace std
