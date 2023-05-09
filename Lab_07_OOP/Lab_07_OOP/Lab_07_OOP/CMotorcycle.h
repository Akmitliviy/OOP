#pragma once
#include "CVehicle.h"

class CMotorcycle : public CVehicle {
public:
    void PrintName();

    CMotorcycle() = delete;
    CMotorcycle(string vehicle_name, double additional_weigh = 0);
    virtual ~CMotorcycle(){};


    double GetDistancePerOneLiter(double dUsefulMassInKg) const override;
    double GetServicePricePerThousandKm() const override;

private:
    static double crub_weight_distance;
    static double max_weight;
    static double base_weight;
    static double price_for_service;
    static double volume_of_gas_tank;

};
