#include <math.h>

#include <vector>

template <typename T, class DS>
class Mo {
 public:
  Mo(DS& ds) : ds_(ds), index_(0), prev_(-1) {}
  std::pair<int, T> ProcessQuery() {
    if (prev_ == -1) {
      int bin = sqrt(index_);
      sort(queries_.begin(), queries_.end(),
           [&bin](const Query& a, const Query& b) {
             int ba = a.begin / bin, bb = b.begin / bin;
             if (ba != bb) return ba < bb;
             if (ba % 2 == 0) {
               return a.end < b.end;
             }
             return a.end > b.end;
           });
      prev_ = 0;
      const Query& q = queries_[0];
      Add(q.begin, q.end);
      return {q.index, ds_.Get()};
    }
    const Query& p = queries_[prev_];
    const Query& c = queries_[prev_ + 1];
    ++prev_;
    Add(c.begin, p.begin);
    Del(p.begin, c.begin);
    Add(p.end, c.end);
    Del(c.end, p.end);
    return {c.index, ds_.Get()};
  }
  void AddQuery(int begin, int end) {
    queries_.push_back({begin, end, index_++});
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
  int index_, prev_;
  std::vector<Query> queries_;
};
