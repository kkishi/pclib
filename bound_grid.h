#include <optional>
#include <ostream>
#include <vector>

struct Coord {
  int x, y;
};

std::ostream& operator<<(std::ostream& os, const Coord& c) {
  os << "{" << c.x << "," << c.y << "}";
  return os;
}

template <typename State>
class BoundGrid {
 public:
  BoundGrid(int x, int y) : grid_(x * 2 + 1, std::vector(y * 2 + 1, State())) {}
  bool InBounds(const Coord& c) const {
    std::size_t x = coord(c.x), y = coord(c.y);
    return 0 <= x && x < grid_.size() && 0 <= y && y < grid_[0].size();
  }
  State& StateOf(const Coord& c) { return grid_[coord(c.x)][coord(c.y)]; }
  State& Boundary(const Coord& c, int dx, int dy) {
    return grid_[coord(c.x) + dx][coord(c.y) + dy];
  }
  void Debug(std::ostream& os,
             char to_char(const State& s, std::optional<char> boundary)) const {
    auto is_boundary = [](int x) -> bool { return x % 2 == 0; };

    // Print horizontal legend.
    os << "  ";  // Padding for the vertical legend.
    for (std::size_t y = 0; y < grid_[0].size(); ++y) {
      if (is_boundary(y)) {
        os << " ";
      } else {
        os << (y / 2) % 10;
      }
    }
    os << std::endl;

    for (std::size_t x = 0; x < grid_.size(); ++x) {
      // Print vertical legend.
      if (is_boundary(x)) {
        os << "  ";
      } else {
        os << (x / 2) % 10 << " ";
      }

      for (std::size_t y = 0; y < grid_[x].size(); ++y) {
        if (is_boundary(x) && is_boundary(y)) {
          os << "+";
          continue;
        }
        std::optional<char> boundary;
        if (is_boundary(x)) {
          boundary = '-';
        } else if (is_boundary(y)) {
          boundary = '|';
        }
        os << to_char(grid_[x][y], boundary);
      }
      os << std::endl;
    }
  }

 private:
  static std::size_t coord(std::size_t i) { return i * 2 + 1; }

  std::vector<std::vector<State>> grid_;
};
