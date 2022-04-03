#include "debug.h"

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
  debug(int{42});
  debug((array<int, 4>{42}));
  debug((map<int, string>{{42, "foo"}}));
  debug(optional<int>{});
  debug(optional<int>{42});
  debug((pair<int, double>{1, 2.5}));
  debug((set<int>{1, 2, 3}));
  debug(string{"str"});
  debug((tuple<int, int, int>{4, 5, 6}));
  debug((vector<int>{1, 2, 3}));
  int i = 42;
  debug(&i);
  debug((int*){nullptr});
  debug((map<pair<set<int>, vector<pair<string, double>>>,
             array<tuple<string>, 1>>{}));
}
