#include "pch.h"

TEST(CVehicleTest, CalculateDistanceWithWeightTest) {
    CVehicle v(18000, 2000, 5000, 50, 3500);
    double expected_distance = 17370;
    double actual_distance = v.GetDistanceWithWeight();
    EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
}

TEST(CVehicleTest, CalculatePriceForServiceTest) {
    CVehicle v(18000, 2000, 5000, 50, 3500);
    double expected_price = 50; 
    double actual_price = v.GetPriceForService();
    EXPECT_DOUBLE_EQ(expected_price, actual_price);
}

TEST(CVehicleTest, CalculateMaxWeightTest) {
    CVehicle v(18000, 2000, 5000, 50, 3500);
    double expected_max_weight = 5000;
    double actual_max_weight = v.GetMaxWeight();
    EXPECT_DOUBLE_EQ(expected_max_weight, actual_max_weight);
}

TEST(CCarTest, PrintNameTest) {
    CCar toyota("Toyota Corolla");
    testing::internal::CaptureStdout();
    toyota.PrintName();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("CCar\n\n", output);
}

TEST(CCarTest, ConstructorTest) {
    CCar toyota("Toyota Corolla", 100);
    double expected_distance = 284.83199999999999;
    double actual_distance = toyota.GetDistanceWithWeight();
    EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
    double expected_max_weight = 2510;
    double actual_max_weight = toyota.GetMaxWeight();
    EXPECT_DOUBLE_EQ(expected_max_weight, actual_max_weight);
}

TEST(CTruckTest, PrintNameTest) {
    CTruck volvo("Volvo");
    testing::internal::CaptureStdout();
    volvo.PrintName();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("CTruck\n\n", output);
}

TEST(CTruckTest, ConstructorTest) {
    CTruck volvo("Volvo", 1000);
    double expected_distance = 656;
    double actual_distance = volvo.GetDistanceWithWeight();
    EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
    double expected_max_weight = 27215.5;
    double actual_max_weight = volvo.GetMaxWeight();
    EXPECT_DOUBLE_EQ(expected_max_weight, actual_max_weight);
}

TEST(CMotorcycleTest, PrintNameTest) {
    CMotorcycle kawasaki("Kawasaki H2");
    testing::internal::CaptureStdout();
    kawasaki.PrintName();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("CMotorcycle\n\n", output);
}

TEST(CMotorcycleTest, ConstructorTest) {
    CMotorcycle kawasaki("Kawasaki H2", 100);
    double expected_distance = 89.805599999999998;
    double actual_distance = kawasaki.GetDistanceWithWeight();
    EXPECT_DOUBLE_EQ(expected_distance, actual_distance);
    double expected_max_weight = 292;
    double actual_max_weight = kawasaki.GetMaxWeight();
    EXPECT_DOUBLE_EQ(expected_max_weight, actual_max_weight);
}
