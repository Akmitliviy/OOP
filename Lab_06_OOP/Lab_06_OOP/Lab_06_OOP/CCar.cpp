#include "CCar.h"

void CCar::PrintName() {
    cout << "CCar\n\n";
}

CCar::CCar(string vehicle_name, double additional_weigh) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
    this->vehicle_name = vehicle_name;
}

double CCar::max_weight = 2'510;
double CCar::base_weight = 1'100;
double CCar::crub_weight_distance = 288;
double CCar::price_for_service = 137.41;