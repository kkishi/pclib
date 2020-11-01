#include <random>

class Random {
 public:
  Random() : generator_(device_()) {}
  int64_t Int(int64_t a, int64_t b) {
    return std::uniform_int_distribution<int64_t>(a, b)(generator_);
  }
  char Alpha() { return 'a' + Int(0, 25); }

 private:
  std::random_device device_;
  std::mt19937 generator_;
};
