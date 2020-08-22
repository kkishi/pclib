#include "rolling_hash.h"

#include <unordered_set>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(rollinghash, simple) {
  using rhash = RollingHash<>;
  std::unordered_set<rhash> s;
  for (auto& str : std::vector<std::string>{"abc", "def", "ghi"}) {
    rhash h;
    for (char c : str) h.Add(c);
    s.insert(h);
  }
  EXPECT_EQ(s.size(), 3);
}
