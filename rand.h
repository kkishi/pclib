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
  char Alpha() { return Int('a', 'z'); }
  template <typename T>
  void Shuffle(std::vector<T>& v) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
      std::swap(v[i], v[Int(i, v.size() - 1)]);
    }
  }
  std::vector<int64_t> Permutation(int64_t n) {
    std::vector<int64_t> v(n);
    std::iota(v.begin(), v.end(), 1);
    Shuffle(v);
    return v;
  }
  std::vector<std::pair<int64_t, int64_t>> Tree(int64_t n) {
    std::vector<std::pair<int64_t, int64_t>> v;
    for (int64_t i = 1; i < n; ++i) {
      int64_t j = Int(0, i - 1);
      v.emplace_back(j + 1, i + 1);
    }
    return v;
  }

 private:
  std::random_device device_;
  std::mt19937 generator_;
};
