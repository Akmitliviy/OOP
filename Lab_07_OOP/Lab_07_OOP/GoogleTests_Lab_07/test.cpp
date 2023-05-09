#include "pch.h"

TEST(Inheritance, CostOfTransportation) {
	const size_t size = 10;
	vector<unique_ptr<CVehicle>> list_of_cars(size);
	vector<unique_ptr<CVehicle>> list_of_trucks(size);
	vector<unique_ptr<CVehicle>> list_of_motorcycles(size);

	for (int i = 0; i < size; i++) {
		list_of_cars[i] = make_unique<CCar>("Hello", 100);
	}
	for (int i = 0; i < size; i++) {
		list_of_trucks[i] = make_unique<CTruck>("Hello", 100);
	}
	for (int i = 0; i < size; i++) {
		list_of_motorcycles[i] = make_unique<CMotorcycle>("Hello", 100);
	}

	double cost_cars = CostOfTransportation(list_of_cars, 6000, 180);
	double cost_trucks = CostOfTransportation(list_of_trucks, 300000, 500);
	double cost_motorcycles = CostOfTransportation(list_of_motorcycles, 2000, 40);

	EXPECT_DOUBLE_EQ(cost_cars, 74.2014);
	EXPECT_DOUBLE_EQ(cost_trucks, 0);
	EXPECT_DOUBLE_EQ(cost_motorcycles, 96.88);
}