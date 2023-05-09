#include "CCar.h"

void CCar::PrintName() {
    cout << "CCar\n\n";
}

CCar::CCar(string vehicle_name, double additional_weigh) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
    this->vehicle_name = vehicle_name;
}

double CCar::GetDistancePerOneLiter(double dUsefulMassInKg) const {
    return distance_with_weight / volume_of_gas_tank;
}
double CCar::GetServicePricePerThousandKm() const {
    return price_for_service;
}

double CCar::max_weight = 2'510;
double CCar::base_weight = 1'100;
double CCar::crub_weight_distance = 288;
double CCar::price_for_service = 137.41;
double CCar::volume_of_gas_tank = 55;