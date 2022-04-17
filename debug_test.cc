#define DEBUG 1
#include "debug.h"
#undef DEBUG

#include <set>
#include <vector>

#include "gtest/gtest.h"

TEST(debug, all) {
  using std::array;
  using std::is_same;
  using std::map;
  using std::numeric_limits;
  using std::optional;
  using std::pair;
  using std::set;
  using std::string;
  using std::tuple;
  using std::vector;

  // Just confirm that it doesn't cause compilation error.
  dbg(int{42});
  dbg((array<int, 4>{42}));
  dbg((map<int, string>{{42, "foo"}}));
  dbg(optional<int>{});
  dbg(optional<int>{42});
  dbg((pair<int, double>{1, 2.5}));
  dbg((set<int>{1, 2, 3}));
  dbg(string{"str"});
  dbg((tuple<int, int, int>{4, 5, 6}));
  dbg((vector<int>{1, 2, 3}));
  int i = 42;
  dbg(&i);
  dbg((int*){nullptr});
  dbg((map<pair<set<int>, vector<pair<string, double>>>,
           array<tuple<string>, 1>>{}));
}
