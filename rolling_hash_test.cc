#include "rolling_hash.h"

#include <unordered_set>

#include "gtest/gtest.h"
#include "primitive_root.h"

TEST(rollinghash, simple) {
  std::unordered_set<RollingHash> s;
  for (auto& str : std::vector<std::string>{"abc", "def", "ghi"}) {
    RollingHash h;
    for (char c : str) h.PushBack(c);
    s.insert(h);
  }
  EXPECT_EQ(s.size(), 3);
}

TEST(rollinghash, base) {
  EXPECT_TRUE(IsPrimitiveRoot(RollingHash::base(), RollingHash::mod()));
}
