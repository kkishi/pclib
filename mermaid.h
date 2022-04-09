#include <cassert>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

#include "debug.h"

namespace mermaid {

class Flowchart {
 public:
  template <typename... Ts>
  void Node(int i, const Ts&... args) {
    std::stringstream ss;
    debug(ss, args...);
    node_[i].emplace_back(ss.str());
  }
  template <typename... Ts>
  void Edge(int u, int v, const Ts&... args) {
    std::stringstream ss;
    debug(ss, args...);
    edge_[{u, v}].emplace_back(ss.str());
  }
  bool WriteTo(std::string file) const {
    std::ofstream fs(file);
    if (!fs.is_open()) return false;
    fs << "flowchart TD;" << std::endl;
    for (const auto& [i, ss] : node_) {
      fs << "  " << i << "((" << i;
      for (const auto& s : ss) {
        fs << "\\n" << s;
      }
      fs << "));" << std::endl;
    }
    for (const auto& [p, ss] : edge_) {
      auto [u, v] = p;
      fs << "  " << u << "-->";
      if (!ss.empty()) {
        fs << "|";
        for (size_t i = 0; i < ss.size(); ++i) {
          if (i > 0) fs << "\\n";
          fs << ss[i];
        }
        fs << "|";
      }
      fs << v << ";" << std::endl;
    }
    fs.flush();
    fs.close();
    return true;
  }

 private:
  std::map<int32_t, std::vector<std::string>> node_;
  std::map<std::pair<int32_t, int32_t>, std::vector<std::string>> edge_;
};

}  // namespace mermaid
