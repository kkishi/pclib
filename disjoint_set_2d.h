#ifndef DISJOINT_SET_2D_H_
#define DISJOINT_SET_2D_H_

#include "disjoint_set.h"

class DisjointSet2D {
 public:
  DisjointSet2D(int h, int w) : h_(h), w_(w), ds_(h * w) {}
  int Find(int r, int c) { return ds_.Find(Index(r, c)); }
  void Union(int ri, int ci, int rj, int cj) {
    ds_.Union(Index(ri, ci), Index(rj, cj));
  }

 private:
  int Index(int r, int c) const { return r * w_ + c; }
  const int h_, w_;
  DisjointSet ds_;
};

#endif  // DISJOINT_SET_2D_H_
