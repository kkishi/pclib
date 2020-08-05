#include <math.h>

#include <vector>

template <typename T, class DS>
class Mo {
 public:
  Mo(DS& ds) : ds_(ds) {}
  void AddQuery(int begin, int end) {
    int index = queries_.size();
    queries_.push_back({begin, end, index});
  }
  std::vector<T> ProcessQueries() {
    int bin = sqrt(queries_.size());
    sort(queries_.begin(), queries_.end(),
         [&bin](const Query& a, const Query& b) {
           int c = a.begin / bin, d = b.begin / bin;
           if (c != d) return c < d;
           if (c % 2 == 0) {
             return a.end < b.end;
           }
           return a.end > b.end;
         });
    std::vector<T> ret(queries_.size());
    Query p = {0, 0, 0};
    for (std::size_t i = 0; i < queries_.size(); ++i) {
      const Query& c = queries_[i];
      Add(c.begin, p.begin);
      Del(p.begin, c.begin);
      Add(p.end, c.end);
      Del(c.end, p.end);
      ret[c.index] = ds_.Get();
      p = c;
    }
    return ret;
  }

 private:
  struct Query {
    int begin, end, index;
  };
  void Add(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      ds_.Add(i);
    }
  }
  void Del(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      ds_.Del(i);
    }
  }
  DS& ds_;
  std::vector<Query> queries_;
};
