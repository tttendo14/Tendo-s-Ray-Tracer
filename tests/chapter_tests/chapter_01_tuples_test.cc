#include <gtest/gtest.h>

#include <cmath>

#include "float_compare.hpp"
#include "tuples.hpp"

namespace {

void expectTupleNear(const tuple::Tuple &actual, const tuple::Tuple &expected) {
  EXPECT_NEAR(actual.x(), expected.x(), math::EPS);
  EXPECT_NEAR(actual.y(), expected.y(), math::EPS);
  EXPECT_NEAR(actual.z(), expected.z(), math::EPS);
  EXPECT_NEAR(actual.w(), expected.w(), math::EPS);
}

} // namespace

TEST(Chapter01Tuples, TupleWithWOneIsAPoint) {
  const tuple::Tuple a{4.3, -4.2, 3.1, 1.0};

  EXPECT_DOUBLE_EQ(a.x(), 4.3);
  EXPECT_DOUBLE_EQ(a.y(), -4.2);
  EXPECT_DOUBLE_EQ(a.z(), 3.1);
  EXPECT_DOUBLE_EQ(a.w(), 1.0);
  EXPECT_TRUE(a.isPoint());
  EXPECT_FALSE(a.isVector());
}

TEST(Chapter01Tuples, TupleWithWZeroIsAVector) {
  const tuple::Tuple a{4.3, -4.2, 3.1, 0.0};

  EXPECT_DOUBLE_EQ(a.x(), 4.3);
  EXPECT_DOUBLE_EQ(a.y(), -4.2);
  EXPECT_DOUBLE_EQ(a.z(), 3.1);
  EXPECT_DOUBLE_EQ(a.w(), 0.0);
  EXPECT_FALSE(a.isPoint());
  EXPECT_TRUE(a.isVector());
}

TEST(Chapter01Tuples, PointFactoryCreatesTupleWithWOne) {
  expectTupleNear(tuple::point(4, -4, 3), tuple::Tuple{4, -4, 3, 1});
}

TEST(Chapter01Tuples, VectorFactoryCreatesTupleWithWZero) {
  expectTupleNear(tuple::vector(4, -4, 3), tuple::Tuple{4, -4, 3, 0});
}

TEST(Chapter01Tuples, AddingTwoTuples) {
  const tuple::Tuple a1{3, -2, 5, 1};
  const tuple::Tuple a2{-2, 3, 1, 0};

  expectTupleNear(a1 + a2, tuple::Tuple{1, 1, 6, 1});
}

TEST(Chapter01Tuples, SubtractingTwoPoints) {
  expectTupleNear(tuple::point(3, 2, 1) - tuple::point(5, 6, 7),
                  tuple::vector(-2, -4, -6));
}

TEST(Chapter01Tuples, SubtractingVectorFromPoint) {
  expectTupleNear(tuple::point(3, 2, 1) - tuple::vector(5, 6, 7),
                  tuple::point(-2, -4, -6));
}

TEST(Chapter01Tuples, SubtractingTwoVectors) {
  expectTupleNear(tuple::vector(3, 2, 1) - tuple::vector(5, 6, 7),
                  tuple::vector(-2, -4, -6));
}

TEST(Chapter01Tuples, SubtractingVectorFromZeroVector) {
  expectTupleNear(tuple::vector(0, 0, 0) - tuple::vector(1, -2, 3),
                  tuple::vector(-1, 2, -3));
}

TEST(Chapter01Tuples, NegatingATuple) {
  const tuple::Tuple a{1, -2, 3, -4};

  expectTupleNear(-a, tuple::Tuple{-1, 2, -3, 4});
}

TEST(Chapter01Tuples, MultiplyingATupleByAScalar) {
  const tuple::Tuple a{1, -2, 3, -4};

  expectTupleNear(a * 3.5, tuple::Tuple{3.5, -7, 10.5, -14});
}

TEST(Chapter01Tuples, MultiplyingATupleByAFraction) {
  const tuple::Tuple a{1, -2, 3, -4};

  expectTupleNear(a * 0.5, tuple::Tuple{0.5, -1, 1.5, -2});
}

TEST(Chapter01Tuples, DividingATupleByAScalar) {
  const tuple::Tuple a{1, -2, 3, -4};

  expectTupleNear(a / 2, tuple::Tuple{0.5, -1, 1.5, -2});
}

TEST(Chapter01Tuples, MagnitudeOfUnitXAxisVector) {
  EXPECT_DOUBLE_EQ(tuple::vector(1, 0, 0).magnitude(), 1);
}

TEST(Chapter01Tuples, MagnitudeOfUnitYAxisVector) {
  EXPECT_DOUBLE_EQ(tuple::vector(0, 1, 0).magnitude(), 1);
}

TEST(Chapter01Tuples, MagnitudeOfUnitZAxisVector) {
  EXPECT_DOUBLE_EQ(tuple::vector(0, 0, 1).magnitude(), 1);
}

TEST(Chapter01Tuples, MagnitudeOfPositiveVector) {
  EXPECT_NEAR(tuple::vector(1, 2, 3).magnitude(), std::sqrt(14), math::EPS);
}

TEST(Chapter01Tuples, MagnitudeOfNegativeVector) {
  EXPECT_NEAR(tuple::vector(-1, -2, -3).magnitude(), std::sqrt(14), math::EPS);
}

TEST(Chapter01Tuples, NormalizingXAxisVector) {
  expectTupleNear(tuple::vector(4, 0, 0).normalize(), tuple::vector(1, 0, 0));
}

TEST(Chapter01Tuples, NormalizingArbitraryVector) {
  expectTupleNear(tuple::vector(1, 2, 3).normalize(),
                  tuple::vector(0.26726, 0.53452, 0.80178));
}

TEST(Chapter01Tuples, MagnitudeOfNormalizedVectorIsOne) {
  EXPECT_NEAR(tuple::vector(1, 2, 3).normalize().magnitude(), 1, math::EPS);
}

TEST(Chapter01Tuples, DotProductOfTwoTuples) {
  EXPECT_DOUBLE_EQ(tuple::vector(1, 2, 3).dot(tuple::vector(2, 3, 4)), 20);
}

TEST(Chapter01Tuples, CrossProductOfTwoVectors) {
  const auto a = tuple::vector(1, 2, 3);
  const auto b = tuple::vector(2, 3, 4);

  expectTupleNear(a.cross(b), tuple::vector(-1, 2, -1));
  expectTupleNear(b.cross(a), tuple::vector(1, -2, 1));
}
