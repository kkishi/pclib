#include <random>

class Rand {
 public:
  Rand() : generator_(device_()) {}
  int64_t Int(int64_t a, int64_t b) {
    return std::uniform_int_distribution<int64_t>(a, b)(generator_);
  }
  double Double(double a, double b) {
    return std::uniform_real_distribution<double>(a, b)(generator_);
  }
  char Alpha() { return 'a' + Int(0, 25); }

 private:
  std::random_device device_;
  std::mt19937 generator_;
};
