#include "CMotorcycle.h"

void CMotorcycle::PrintName() {
    cout << "CMotorcycle\n\n";
}

CMotorcycle::CMotorcycle(string vehicle_name, double additional_weigh) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
    this->vehicle_name = vehicle_name;
}

double CMotorcycle::max_weight = 292;
double CMotorcycle::base_weight = 216;
double CMotorcycle::crub_weight_distance = 90;
double CMotorcycle::price_for_service = 346;