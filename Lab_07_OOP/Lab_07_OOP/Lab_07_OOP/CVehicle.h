#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class CVehicle {
public:
    void PrintName();

    virtual double GetDistancePerOneLiter(double dUsefulMassInKg) const = 0;
    virtual double GetServicePricePerThousandKm() const = 0;

    double GetDistanceWithWeight();

    double GetPriceForService();
    double GetMaxWeight();
    double GetBaseWeight();
    double GetCurrentWeight();

    void PrintDistanceWithWeight();
    void PrintPriceForService();
    void PrintMaxWeight();

    CVehicle(double crub_weight_distance, double base_weight, double max_weight, double price_for_service, double real_weight);
    virtual ~CVehicle();
protected:

    double real_weight;
    double distance_with_weight;
    double price_for_service;
    double max_weight;
    double base_weight;
    string vehicle_name;

    double CalculateDistanceWithWeight(double weight, double crub_weight_distance);
private:

    double CalculatePriceForService(double price_for_service);
    double CalculateMaxWeight(double max_weight);

};

double CostOfTransportation(const vector<unique_ptr<CVehicle>>& list_of_vehicles, const double weight, const double distance);