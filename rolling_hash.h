#include <cstdint>
#include <functional>

template <uint64_t Base = 100000007>
class RollingHash {
 public:
  void Add(int i) { hash_ = hash_ * Base + i; }
  uint64_t hash() const { return hash_; }
  bool operator==(const RollingHash& h) const { return hash_ == h.hash_; }

 private:
  uint64_t hash_ = 0;
};

namespace std {
template <uint64_t Base>
class hash<RollingHash<Base>> {
 public:
  size_t operator()(const RollingHash<Base>& h) const {
    return hash<uint64_t>()(h.hash());
  }
};
}  // namespace std
