#include "suffix_array.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(suffix_array, simple) {
  /*
    10 a
    7  abra
    0  abracadabra
    3  acadabra
    5  adabra
    8  bra
    1  bracadabra
    4  cadabra
    6  dabra
    9  ra
    2  racadabra
  */
  EXPECT_THAT(SuffixArray("abracadabra"),
              ElementsAre(10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2));
}

TEST(suffix_array, search) {
  std::string s = "abracadabra";
  std::vector<int64_t> sa = SuffixArray(s);
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + j <= n; ++j) {
      std::string sub = s.substr(i, j);
      auto [l, r] = SuffixArraySearch(s, sa, sub);
      for (int k = 0; k < n; ++k) {
        if (l <= k && k < r) {
          EXPECT_EQ(sub, s.substr(sa[k], j));
        } else {
          EXPECT_TRUE(n - sa[k] < j || sub != s.substr(sa[k], j));
        }
      }
    }
  }
}
