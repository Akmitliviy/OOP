#pragma once
#include <iostream>
#include <string>

using namespace std;

class CVehicle {
public:
    void PrintName();

    double GetDistanceWithWeight();
    double GetPriceForService();
    double GetMaxWeight();

    void PrintDistanceWithWeight();
    void PrintPriceForService();
    void PrintMaxWeight();

    CVehicle(double crub_weight_distance, double base_weight, double max_weight, double price_for_service, double real_weight);
protected:

    double real_weight;
    double distance_with_weight;
    double price_for_service;
    double max_weight;
    double base_weight;
    string vehicle_name;

private:

    double CalculateDistanceWithWeight(double weight, double crub_weight_distance);
    double CalculatePriceForService(double price_for_service);
    double CalculateMaxWeight(double max_weight);

};