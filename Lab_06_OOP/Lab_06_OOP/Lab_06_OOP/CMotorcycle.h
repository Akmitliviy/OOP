#pragma once
#include "CVehicle.h"

class CMotorcycle : public CVehicle {
public:
    void PrintName();

    CMotorcycle() = delete;

    CMotorcycle(string vehicle_name, double additional_weigh = 0);

private:
    static double crub_weight_distance;
    static double max_weight;
    static double base_weight;
    static double price_for_service;

};
