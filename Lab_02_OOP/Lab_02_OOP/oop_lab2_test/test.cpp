#include "pch.h"
#include "../Lab_02_OOP/lab2.h"

TEST(GetBoxVolume, HandlesNegativeInput) {
	EXPECT_TRUE(isnan(GetBoxVolume(8.34, 34.2, -1.34)));
	EXPECT_TRUE(isnan(GetBoxVolume(32.62, -1.37, 2.57)));
	EXPECT_TRUE(isnan(GetBoxVolume(65.32, -1.24, -1.4)));
	EXPECT_TRUE(isnan(GetBoxVolume(-1.32, 7.2, 9.34)));
	EXPECT_TRUE(isnan(GetBoxVolume(-1.32, 24.38, -1.01)));
	EXPECT_TRUE(isnan(GetBoxVolume(-1.32, -1.15, 57.3)));
	EXPECT_TRUE(isnan(GetBoxVolume(-1.32, -1.83, -1.14)));
}

TEST(GetBoxVolume, HandlesZeroInput) {
	EXPECT_DOUBLE_EQ(GetBoxVolume(0, 0, 0), 0);
}

TEST(GetBoxVolume, HandlesCommonInput) {
	EXPECT_DOUBLE_EQ(GetBoxVolume(8.34, 34.2, 37.34), 10'650.41352);
	EXPECT_DOUBLE_EQ(GetBoxVolume(32.62, 0.37, 5.57), 67.226558);
	EXPECT_DOUBLE_EQ(GetBoxVolume(65.32, 1.24, 1.4), 113.39552);
}

TEST(GetBoxVolume, HandlesLargeInput) {
	EXPECT_DOUBLE_EQ(GetBoxVolume(1000000.0, 1000000.0, 1000000.0), 1.0e+18);
}