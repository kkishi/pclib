#include "mo.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(mo, abc174_sample2) {
  std::vector<int> c = {2, 5, 6, 5, 2, 1, 7, 9, 7, 2};
  std::vector<std::pair<int64_t, int64_t>> q = {{4, 5},  {1, 4}, {5, 7}, {1, 2},
                                                {6, 8},  {6, 9}, {0, 8}, {5, 9},
                                                {7, 10}, {5, 8}};

  int n = c.size();
  std::vector<int> kinds(n);
  int unique_kinds = 0;

  auto add = [&](int i) {
    if (kinds[c[i] - 1]++ == 0) {
      ++unique_kinds;
    }
  };
  auto del = [&](int i) {
    if (--kinds[c[i] - 1] == 0) {
      --unique_kinds;
    }
  };
  auto get = [&]() { return unique_kinds; };

  EXPECT_THAT(Mo(add, del, get, q), ElementsAre(1, 2, 2, 1, 2, 2, 6, 3, 3, 3));
}
