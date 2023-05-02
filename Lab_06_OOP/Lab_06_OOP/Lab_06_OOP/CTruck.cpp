#include "CTruck.h"

void CTruck::PrintName(){
    cout << "CTruck\n\n";
}

CTruck::CTruck(string vehicle_name, double additional_weigh) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
    this->vehicle_name = vehicle_name;
}

double CTruck::max_weight = 27'215.5;
double CTruck::base_weight = 18'000;
double CTruck::crub_weight_distance = 800;
double CTruck::price_for_service = 659;