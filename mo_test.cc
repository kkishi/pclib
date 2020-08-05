#include "mo.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

struct DS {
  DS(int n) : c(n), kinds(n), unique_kinds(0) {}
  void Add(int i) {
    if (kinds[c[i] - 1]++ == 0) {
      ++unique_kinds;
    }
  }
  void Del(int i) {
    if (--kinds[c[i] - 1] == 0) {
      --unique_kinds;
    }
  }
  int Get() const { return unique_kinds; }
  std::vector<int> c;
  std::vector<int> kinds;
  int unique_kinds;
};

TEST(mo, abc174_sample2) {
  std::vector<int> c = {2, 5, 6, 5, 2, 1, 7, 9, 7, 2};
  DS ds(c.size());
  ds.c = c;

  Mo<int, DS> mo(ds);

  std::vector<std::pair<int, int>> q = {{5, 5},  {2, 4}, {6, 7}, {2, 2},
                                        {7, 8},  {7, 9}, {1, 8}, {6, 9},
                                        {8, 10}, {6, 8}};
  for (auto [l, r] : q) mo.AddQuery(l - 1, r);

  EXPECT_THAT(mo.ProcessQueries(), ElementsAre(1, 2, 2, 1, 2, 2, 6, 3, 3, 3));
}
