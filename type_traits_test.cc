#include "type_traits.h"

#include "gtest/gtest.h"

TEST(type_traits, all) {
  using std::array;
  using std::optional;
  using std::pair;
  using std::string;
  using std::tuple;
  using std::vector;

  // Raw pointers and optionals are dereferenceable.
  EXPECT_TRUE(is_dereferenceable<int*>::value);
  EXPECT_TRUE(is_dereferenceable<optional<int>>::value);
  EXPECT_FALSE(is_dereferenceable<int>::value);
  EXPECT_FALSE((is_dereferenceable<tuple<int, int>>::value));

  // Container like things are iterable. One caveat is that string is iterable,
  // but we don't generally want to treat it as such.
  EXPECT_TRUE(is_iterable<vector<int>>::value);
  EXPECT_TRUE((is_iterable<array<int, 1000000>>::value));
  EXPECT_FALSE((is_iterable<tuple<int, int, int>>::value));
  EXPECT_TRUE(is_iterable<string>::value);

  // Tuple like things are applicable (can work with std::apply).
  EXPECT_TRUE((is_applicable<pair<int, int>>::value));
  EXPECT_TRUE((is_applicable<tuple<int, int>>::value));
  EXPECT_FALSE(is_applicable<vector<int>>::value);
  EXPECT_TRUE((is_applicable<array<int, 1000000>>::value));
}
