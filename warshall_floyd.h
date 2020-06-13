#include <algorithm>
#include <vector>

template <typename T>
void WarshallFloyd(std::vector<std::vector<T>>& v) {
  for (std::size_t k = 0; k < v.size(); ++k) {
    for (std::size_t i = 0; i < v.size(); ++i) {
      for (std::size_t j = 0; j < v.size(); ++j) {
        v[i][j] = std::min(v[i][j], v[i][k] + v[k][j]);
      }
    }
  }
}
