#include "binary_trie.h"

#include "gtest/gtest.h"

TEST(binary_trie, simple) {
  BinaryTrie t;
  t.Insert(1);
  t.Insert(1);
  t.Insert(3);
  t.Insert(3);
  t.Insert(5);
  t.Insert(5);
  EXPECT_EQ(t.Size(), 6);
  EXPECT_EQ(t.FindByOrder(0), 1);
  EXPECT_EQ(t.FindByOrder(1), 1);
  EXPECT_EQ(t.FindByOrder(2), 3);
  EXPECT_EQ(t.FindByOrder(3), 3);
  EXPECT_EQ(t.FindByOrder(4), 5);
  EXPECT_EQ(t.FindByOrder(5), 5);
  EXPECT_EQ(t.MinElement(), 1);
  EXPECT_EQ(t.MaxElement(), 5);
  t.Erase(1);
  t.Erase(3);
  t.Erase(5);
  EXPECT_EQ(t.Size(), 3);
  EXPECT_EQ(t.FindByOrder(0), 1);
  EXPECT_EQ(t.FindByOrder(1), 3);
  EXPECT_EQ(t.FindByOrder(2), 5);
  EXPECT_EQ(t.MinElement(), 1);
  EXPECT_EQ(t.MaxElement(), 5);
  t.Erase(1);
  t.Erase(5);
  EXPECT_EQ(t.Size(), 1);
  EXPECT_EQ(t.FindByOrder(0), 3);
  EXPECT_EQ(t.MinElement(), 3);
  EXPECT_EQ(t.MaxElement(), 3);
}
