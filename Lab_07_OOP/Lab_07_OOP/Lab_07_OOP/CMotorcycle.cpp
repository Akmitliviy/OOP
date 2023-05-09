#include "CMotorcycle.h"

void CMotorcycle::PrintName() {
    cout << "CMotorcycle\n\n";
}

CMotorcycle::CMotorcycle(string vehicle_name, double additional_weigh) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
    this->vehicle_name = vehicle_name;
}
double CMotorcycle::GetDistancePerOneLiter(double dUsefulMassInKg) const {
    return distance_with_weight / volume_of_gas_tank;
}
double CMotorcycle::GetServicePricePerThousandKm() const {
    return price_for_service;
}

double CMotorcycle::max_weight = 292;
double CMotorcycle::base_weight = 216;
double CMotorcycle::crub_weight_distance = 90;
double CMotorcycle::price_for_service = 346;
double CMotorcycle::volume_of_gas_tank = 17;