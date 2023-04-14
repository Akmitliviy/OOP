#include "pch.h"

SPolynom pol_1{ 2128.353, 9354.3453, 63568.72257, 385561.3747 },
pol_2{ 73427.8745, 5674.12087, 5367.54428, 584.2626 },
pol_3{ 0, 0, 0, 0 },
pol_4{ -2346.2346, -2087.5473, -2326.5428, -23873.45372 }, 
pol_5{ 1'000'000'000'000, 1'000'000'000'000, 1'000'000'000'000, 1'000'000'000'000 };

TEST(CPolynom4Test, Number_of_objects) {
	CPolynom4 p1(pol_1);
	CPolynom4 p2(pol_2);
	CPolynom4 p3(pol_3);
	CPolynom4 p4(pol_4);

	int number_of_objects = CPolynom4::GetNumOfObjects();
	EXPECT_EQ(number_of_objects, 4);
}

TEST(Plus, HandlesNormalInput) {
	CPolynom4 C1(pol_1), C2(pol_2), Sum;

	Sum = C1 + C2;
	SPolynom result = Sum.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, 75'556.2275);
	EXPECT_DOUBLE_EQ(result.b, 15'028.46617);
	EXPECT_DOUBLE_EQ(result.c, 68'936.26685);
	EXPECT_DOUBLE_EQ(result.d, 386'145.6373);

}

TEST(Plus, HandlesZeroInput) {
	CPolynom4 C1(pol_3), C2(pol_2), Sum;

	Sum = C1 + C2;
	SPolynom result = Sum.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, pol_2.a);
	EXPECT_DOUBLE_EQ(result.b, pol_2.b);
	EXPECT_DOUBLE_EQ(result.c, pol_2.c);
	EXPECT_DOUBLE_EQ(result.d, pol_2.d);

}

TEST(Plus, HandlesBigInput) {
	CPolynom4 C1(pol_5), C2(pol_5), Sum;

	Sum = C1 + C2;
	SPolynom result = Sum.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, 2'000'000'000'000);
	EXPECT_DOUBLE_EQ(result.b, 2'000'000'000'000);
	EXPECT_DOUBLE_EQ(result.c, 2'000'000'000'000);
	EXPECT_DOUBLE_EQ(result.d, 2'000'000'000'000);

}

TEST(Plus, HandlesNegativeInput) {
	CPolynom4 C1(pol_1), C2(pol_4), Sum;

	Sum = C1 + C2;
	SPolynom result = Sum.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, 2128.353 - 2346.2346);
	EXPECT_DOUBLE_EQ(result.b, 7'266.798);
	EXPECT_DOUBLE_EQ(result.c, 61'242.17977);
	EXPECT_DOUBLE_EQ(result.d, 361'687.92098);

}

TEST(Minus, HandlesNormalInput) {
	CPolynom4 C1(pol_1), C2(pol_2), Diff;

	Diff = C1 - C2;
	SPolynom result = Diff.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, -71'299.5215);
	EXPECT_DOUBLE_EQ(result.b, 3'680.22443);
	EXPECT_DOUBLE_EQ(result.c, 58'201.17829);
	EXPECT_DOUBLE_EQ(result.d, 384'977.1121);

}

TEST(Minus, HandlesZeroInput) {
	CPolynom4 C1(pol_3), C2(pol_2), Diff;

	Diff = C1 - C2;
	SPolynom result = Diff.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, -pol_2.a);
	EXPECT_DOUBLE_EQ(result.b, -pol_2.b);
	EXPECT_DOUBLE_EQ(result.c, -pol_2.c);
	EXPECT_DOUBLE_EQ(result.d, -pol_2.d);

}

TEST(Minus, HandlesBigInput) {
	CPolynom4 C1(pol_5), C2(pol_5), Diff;

	Diff = C1 - C2;
	SPolynom result = Diff.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, 0);
	EXPECT_DOUBLE_EQ(result.b, 0);
	EXPECT_DOUBLE_EQ(result.c, 0);
	EXPECT_DOUBLE_EQ(result.d, 0);

}

TEST(Minus, HandlesNegativeInput) {
	CPolynom4 C1(pol_4), C2(pol_1), Diff;

	Diff = C1 - C2;
	SPolynom result = Diff.GetPolynom();

	EXPECT_DOUBLE_EQ(result.a, -4'474.5876);
	EXPECT_DOUBLE_EQ(result.b, -11'441.8926);
	EXPECT_DOUBLE_EQ(result.c, -65'895.26537);
	EXPECT_DOUBLE_EQ(result.d, -409'434.82842);

}

TEST(operator90, HandlesInput) {
	CPolynom4 C1(pol_4);

	ldouble result = C1(365.422);

	EXPECT_DOUBLE_EQ(result, -114'766'454'478.6443750189008);

}

TEST(Inverse, HandlesNormalInput) {
	CPolynom4 C1(pol_4);

	CPolynom4 result = !C1;
	SPolynom pol = result.GetPolynom();
	EXPECT_DOUBLE_EQ(pol.a, 2346.2346);
	EXPECT_DOUBLE_EQ(pol.b, 2087.5473);
	EXPECT_DOUBLE_EQ(pol.c, 2326.5428);
	EXPECT_DOUBLE_EQ(pol.d, 23873.45372);

}

TEST(Inverse, HandlesZero) {
	CPolynom4 C1(pol_3);

	CPolynom4 result = !C1;
	SPolynom pol = result.GetPolynom();
	EXPECT_DOUBLE_EQ(pol.a, 0);
	EXPECT_DOUBLE_EQ(pol.b, 0);
	EXPECT_DOUBLE_EQ(pol.c, 0);
	EXPECT_DOUBLE_EQ(pol.d, 0);

}

TEST(CPolynom4Test, AccessOperator) {
	CPolynom4 p;
	p[0] = 2128.353;
	p[1] = 9354.3453;
	p[2] = 63568.72257;
	p[3] = 385561.3747;

	ASSERT_DOUBLE_EQ(p[0], 2128.353);
	ASSERT_DOUBLE_EQ(p[1], 9354.3453);
	ASSERT_DOUBLE_EQ(p[2], 63568.72257);
	ASSERT_DOUBLE_EQ(p[3], 385561.3747);
}

// Test the << operator
TEST(CPolynom4Test, OutputOperator) {
	CPolynom4 p;
	p[0] = 1.0;
	p[1] = 2.0;
	p[2] = 3.0;
	p[3] = 4.0;
	std::ostringstream oss;
	oss << p;
	EXPECT_EQ(oss.str(), "\n\n(1)x^3 + (2)x^2 + (3)x + (4)\n\n");
}

// Test the >> operator
TEST(CPolynom4Test, InputOperator) {
	CPolynom4 p;
	std::istringstream iss("1.0 2.0 3.0 4.0");
	iss >> p;
	EXPECT_DOUBLE_EQ(p[0], 1.0);
	EXPECT_DOUBLE_EQ(p[1], 2.0);
	EXPECT_DOUBLE_EQ(p[2], 3.0);
	EXPECT_DOUBLE_EQ(p[3], 4.0);
}

// Test the * operator
TEST(CPolynom4Test, ScalarMultiplicationOperator) {
	CPolynom4 p(pol_4);
	CPolynom4 result = p * 3.0;
	EXPECT_DOUBLE_EQ(result[0], -7'038.7038);
	EXPECT_DOUBLE_EQ(result[1], -6'262.6419);
	EXPECT_DOUBLE_EQ(result[2], -6'979.6284);
	EXPECT_DOUBLE_EQ(result[3], -71'620.36116);
}

// Test the == operator
TEST(CPolynom4Test, EqualityOperator) {
	CPolynom4 p1(pol_1);
	CPolynom4 p2;
	p2[0] = 2128.353;
	p2[1] = 9354.3453;
	p2[2] = 63568.72257;
	p2[3] = 385561.3747;
	EXPECT_TRUE(p1 == p2);
}

// Test the != operator
TEST(CPolynom4Test, InequalityOperator) {
	CPolynom4 p1(pol_1);
	CPolynom4 p2;
	p2[0] = 2128.353;
	p2[1] = 9354.3453;
	p2[2] = 63568.72257;
	p2[3] = 385561.3748;
	EXPECT_TRUE(p1 != p2);
}