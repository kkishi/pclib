#include "disjointset.h"

#include "gtest/gtest.h"

TEST(disjointset, simple) {
  DisjointSet ds(3);
  ds.Union(0, 1);
  EXPECT_EQ(ds.Find(1), ds.Find(0));
  EXPECT_EQ(ds.Find(2), 2);
  EXPECT_EQ(ds.Size(0), 2);
  EXPECT_EQ(ds.Size(2), 1);
}
