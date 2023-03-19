#include "pch.h"

TEST(RootsFinder, Dichotomy0000) {
	SPolynom pol = { 0, 0, 0, 0 };
	RootsFinder test(pol);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[0]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[1]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Dichotomy0001) {
	SPolynom pol = { 0, 0, 0, 1 };
	RootsFinder test(pol);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[0]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[1]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Dichotomy0010) {
	SPolynom pol = { 0, 0, 1, 0 };
	RootsFinder test(pol);
	SResult test_result = { NULL, NULL, NULL, 0 };
	EXPECT_DOUBLE_EQ(test.FindByDichotomy().roots[0], 0);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[1]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Dichotomy0100) {
	SPolynom pol = { 0, 1, 0, 0 };
	RootsFinder test(pol);
	EXPECT_DOUBLE_EQ(test.FindByDichotomy().roots[0], 0);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[1]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Dichotomy1000) {
	SPolynom pol = { 1, 0, 0, 0 };
	RootsFinder test(pol);
	EXPECT_DOUBLE_EQ(test.FindByDichotomy().roots[0], 0);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[1]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Dichotomy0011) {
	SPolynom pol = { 0, 0, 1, 1 };
	RootsFinder test(pol);
	EXPECT_DOUBLE_EQ(test.FindByDichotomy().roots[0], -1);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[1]));
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Dichotomy0110) {
	SPolynom pol = { 0, 1, 1, 0 };
	RootsFinder test(pol);
	EXPECT_TRUE(test.FindByDichotomy().roots[0] <= 0.001);
	EXPECT_DOUBLE_EQ(test.FindByDichotomy().roots[1], -1);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Dichotomy1100) {
	SPolynom pol = { 1, 1, 0, 0 };
	RootsFinder test(pol);
	EXPECT_TRUE(test.FindByDichotomy().roots[0] <= 0.001);
	EXPECT_DOUBLE_EQ(test.FindByDichotomy().roots[1], -1);
	EXPECT_TRUE(isnan(test.FindByDichotomy().roots[2]));
}

TEST(RootsFinder, Secant0000) {
	SPolynom pol = { 0, 0, 0, 0 };
	RootsFinder test(pol);
  EXPECT_TRUE(isnan(test.FindBySecant().roots[0]));
  EXPECT_TRUE(isnan(test.FindBySecant().roots[1]));
  EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}

TEST(RootsFinder, Secant0001) {
	SPolynom pol = { 0, 0, 0, 1 };
	RootsFinder test(pol);
  EXPECT_TRUE(isnan(test.FindBySecant().roots[0]));
  EXPECT_TRUE(isnan(test.FindBySecant().roots[1]));
  EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}

TEST(RootsFinder, Secant0010) {
	SPolynom pol = { 0, 0, 1, 0 };
	RootsFinder test(pol);
	SResult test_result = { NULL, NULL, NULL, 0 };
  EXPECT_DOUBLE_EQ(test.FindBySecant().roots[0], 0);
  EXPECT_TRUE(isnan(test.FindBySecant().roots[1]));
  EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}

TEST(RootsFinder, Secant0100) {
	SPolynom pol = { 0, 1, 0, 0 };
	RootsFinder test(pol);
	EXPECT_DOUBLE_EQ(test.FindBySecant().roots[0], 0);
	EXPECT_TRUE(isnan(test.FindBySecant().roots[1]));
	EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}

TEST(RootsFinder, Secant1000) {
	SPolynom pol = { 1, 0, 0, 0 };
	RootsFinder test(pol);
	EXPECT_DOUBLE_EQ(test.FindBySecant().roots[0], 0);
	EXPECT_TRUE(isnan(test.FindBySecant().roots[1]));
	EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}

TEST(RootsFinder, Secant0011) {
	SPolynom pol = { 0, 0, 1, 1 };
	RootsFinder test(pol);
	EXPECT_DOUBLE_EQ(test.FindBySecant().roots[0], -1);
	EXPECT_TRUE(isnan(test.FindBySecant().roots[1]));
	EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}

TEST(RootsFinder, Secant0110) {
	SPolynom pol = { 0, 1, 1, 0 };
	RootsFinder test(pol);
	EXPECT_TRUE(test.FindBySecant().roots[0] <= 0.001);
	EXPECT_DOUBLE_EQ(test.FindBySecant().roots[1], -1);
	EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}

TEST(RootsFinder, Secant1100) {
	SPolynom pol = { 1, 1, 0, 0 };
	RootsFinder test(pol);
	EXPECT_TRUE(test.FindBySecant().roots[0] <= 0.001);
	EXPECT_DOUBLE_EQ(test.FindBySecant().roots[1], -1);
	EXPECT_TRUE(isnan(test.FindBySecant().roots[2]));
}



//////////////////////////////////////////////////



TEST(CPolynom4, AccessorHandlesZero) {
	SPolynom input = { 0, 0, 0, 0 };
	CPolynom4 polynom(input);

	ASSERT_TRUE(input.a == polynom.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom.GetPolynom().d);
}

TEST(CPolynom4, AccessorHandlesBigInput) {
	SPolynom input = { 1000000, 1000000, 1000000, 1000000 };
	CPolynom4 polynom(input);

	ASSERT_TRUE(input.a == polynom.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom.GetPolynom().d);
}

TEST(CPolynom4, AccessorHandlesNegativeInput) {
	SPolynom input = { -4245, -252, -74225, -3742 };
	CPolynom4 polynom(input);

	ASSERT_TRUE(input.a == polynom.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom.GetPolynom().d);
}

TEST(CPolynom4, AccessorHandlesFloatInput) {
	SPolynom input = { 4245.346, -252.2626, -74225.35643, -3742.2457 };
	CPolynom4 polynom(input);

	ASSERT_TRUE(input.a == polynom.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom.GetPolynom().d);
}

TEST(CPolynom4, MutatorHandlesZero) {
	CPolynom4 polynom1(4345.36, 734.3568, 34783.445, 95563.4537);
	SPolynom input = { 0, 0, 0, 0 };

	polynom1.SetPolynom(input);
	ASSERT_TRUE(input.a == polynom1.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom1.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom1.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom1.GetPolynom().d);

	CPolynom4 polynom2(4345.36, 734.3568, 34783.445, 95563.4537);
	polynom2.SetPolynom(0, 0, 0, 0);
	ASSERT_TRUE(input.a == polynom2.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom2.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom2.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom2.GetPolynom().d);
}

TEST(CPolynom4, MutatorHandlesBigInput) {
	CPolynom4 polynom1(4345.36, 734.3568, 34783.445, 95563.4537);
	SPolynom input = { 1000000, 1000000, 1000000, 1000000 };

	polynom1.SetPolynom(input);
	ASSERT_TRUE(input.a == polynom1.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom1.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom1.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom1.GetPolynom().d);

	CPolynom4 polynom2(4345.36, 734.3568, 34783.445, 95563.4537);
	polynom2.SetPolynom(1000000, 1000000, 1000000, 1000000);
	ASSERT_TRUE(input.a == polynom2.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom2.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom2.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom2.GetPolynom().d);
}

TEST(CPolynom4, MutatorHandlesNegativeInput) {
	CPolynom4 polynom1(4345.36, 734.3568, 34783.445, 95563.4537);
	SPolynom input = { -4245, -252, -74225, -3742 };

	polynom1.SetPolynom(input);
	ASSERT_TRUE(input.a == polynom1.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom1.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom1.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom1.GetPolynom().d);

	CPolynom4 polynom2(4345.36, 734.3568, 34783.445, 95563.4537);
	polynom2.SetPolynom(-4245, -252, -74225, -3742);
	ASSERT_TRUE(input.a == polynom2.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom2.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom2.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom2.GetPolynom().d);
}

TEST(CPolynom4, MutatorHandlesFloatInput) {
	CPolynom4 polynom1(4345.36, 734.3568, 34783.445, 95563.4537);
	SPolynom input = { 4245.346, -252.2626, -74225.35643, -3742.2457 };

	polynom1.SetPolynom(input);
	ASSERT_TRUE(input.a == polynom1.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom1.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom1.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom1.GetPolynom().d);

	CPolynom4 polynom2(4345.36, 734.3568, 34783.445, 95563.4537);
	polynom2.SetPolynom(4245.346, -252.2626, -74225.35643, -3742.2457);
	ASSERT_TRUE(input.a == polynom2.GetPolynom().a);
	ASSERT_TRUE(input.b == polynom2.GetPolynom().b);
	ASSERT_TRUE(input.c == polynom2.GetPolynom().c);
	ASSERT_TRUE(input.d == polynom2.GetPolynom().d);
}

TEST(CPolynom4, GetResultZero) {
	CPolynom4 polynom(0, 0, 0, 0);
	EXPECT_DOUBLE_EQ(polynom.GetResult(5), 0);
	EXPECT_DOUBLE_EQ(polynom.GetResult(36.2346), 0);
	EXPECT_DOUBLE_EQ(polynom.GetResult(0), 0);
	EXPECT_DOUBLE_EQ(polynom.GetResult(-34534.23), 0);
}

TEST(CPolynom4, GetResultNormal) {
	CPolynom4 polynom(1, -4, -7, 10);
	EXPECT_DOUBLE_EQ(polynom.GetResult(-2), 0);
	EXPECT_DOUBLE_EQ(polynom.GetResult(1), 0);
	EXPECT_DOUBLE_EQ(polynom.GetResult(5), 0);
	EXPECT_DOUBLE_EQ(polynom.GetResult(2), -12);
	EXPECT_TRUE(fabs(polynom.GetResult(3.361) - (- 20.745)) <= 0.001);
}

TEST(CPolynom4, GetDerivativeCanFindZero) {

	CPolynom4 polynom(1, -4, -7, 10);
	EXPECT_TRUE(fabs(polynom.GetDerivative(3.361) - 0) <= 0.001);
	EXPECT_TRUE(fabs(polynom.GetDerivative(-0.6943) - 0) <= 0.001);
}

TEST(CPolynom4, GetDerivativeHandlesNormalInput) {

	CPolynom4 polynom(1, -4, -7, 10);
	EXPECT_DOUBLE_EQ(polynom.GetDerivative(4), 9);
	EXPECT_DOUBLE_EQ(polynom.GetDerivative(6), 53);
}

TEST(CPolynom4, GetIntegralHandlesZero) {

	CPolynom4 polynom(1, -4, -7, 10);
	EXPECT_DOUBLE_EQ(polynom.GetIntegral(0, 0), 0);
	EXPECT_DOUBLE_EQ(polynom.GetIntegral(0, 1), 5.41666666666667);
	EXPECT_DOUBLE_EQ(polynom.GetIntegral(-1, 0), 11.91666666666667);
}

TEST(CPolynom4, GetIntegralHandlesReverce) {

	CPolynom4 polynom(1, -4, -7, 10);
	EXPECT_DOUBLE_EQ(polynom.GetIntegral(1, -1), -17.33333333333333);
	EXPECT_DOUBLE_EQ(polynom.GetIntegral(0, -2), -19.33333333333333);
}

TEST(CPolynom4, GetRootsHandlesZero) {

	CPolynom4 polynom(1, -4, -7, 10);
	EXPECT_TRUE(fabs(polynom.GetRoots().roots[0] - 5) <= 0.001);
	EXPECT_TRUE(fabs(polynom.GetRoots().roots[1] - 1) <= 0.001);
	EXPECT_TRUE(fabs(polynom.GetRoots().roots[2] - (-2)) <= 0.001);

	EXPECT_TRUE(fabs(polynom.GetRoots(-20, 39).roots[0] - 5) <= 0.001);
	EXPECT_TRUE(fabs(polynom.GetRoots(-20, 39).roots[1] - 1) <= 0.001);
	EXPECT_TRUE(fabs(polynom.GetRoots(-20, 39).roots[2] - (-2)) <= 0.001);

	EXPECT_TRUE(fabs(polynom.GetRoots(-23, 13, 0.0000000001).roots[0] - 5) <= 0.0000000001);
	EXPECT_TRUE(fabs(polynom.GetRoots(-23, 13, 0.0000000001).roots[1] - 1) <= 0.0000000001);
	EXPECT_TRUE(fabs(polynom.GetRoots(-23, 13, 0.0000000001).roots[2] - (-2)) <= 0.0000000001);
}