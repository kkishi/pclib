#include "geometry.h"

#include "gtest/gtest.h"

TEST(geometry, vector) {
  Vector<double> a = {3, 4};
  EXPECT_DOUBLE_EQ(a.Norm(), 5);

  Vector<double> b = {5, 6}, c = a + b;
  EXPECT_DOUBLE_EQ(c.x, 8);
  EXPECT_DOUBLE_EQ(c.y, 10);

  c -= a;
  EXPECT_DOUBLE_EQ(c.x, b.x);
  EXPECT_DOUBLE_EQ(c.y, b.y);
}

TEST(geometry, circle) {
  const double kEps = 1e-10;

  Circle<double> a{{0, 0}, 1};
  Circle<double> b{{1, 1}, 1};
  std::vector<Vector<double>> is = a.Intersections(b);
  EXPECT_NEAR(is[0].x, 0, kEps);
  EXPECT_NEAR(is[0].y, 1, kEps);
  EXPECT_NEAR(is[1].x, 1, kEps);
  EXPECT_NEAR(is[1].y, 0, kEps);

  Circle<double> c = {{1, 0}, 4.81837};
  Circle<double> d = {{-1, 0}, 3.21225};
  std::vector<Vector<double>> is2 = c.Intersections(d);
  EXPECT_NEAR(is2[0].x, -3.2245348486, kEps);
  EXPECT_NEAR(is2[0].y, -2.3173249167, kEps);
  EXPECT_NEAR(is2[1].x, -3.2245348486, kEps);
  EXPECT_NEAR(is2[1].y, 2.3173249167, kEps);
}
