#include "CVehicle.h"

void CVehicle::PrintName() {
    cout << "CVehicle\n\n";
}

double CVehicle::GetPriceForService() {
    return price_for_service;
}

double CVehicle::GetMaxWeight() {
    return max_weight;
}
double CVehicle::GetBaseWeight() {
    return base_weight;
}
double CVehicle::GetCurrentWeight() {
    return real_weight;
}

double CVehicle::GetDistanceWithWeight() {
    return distance_with_weight;
}

void CVehicle::PrintDistanceWithWeight() {
    cout << "Max distance with weight of " << real_weight << "kg is: " << distance_with_weight << "km" << endl << endl;
}

void CVehicle::PrintPriceForService() {
    cout << "Price of service for 1000km is: $" << price_for_service << endl << endl;
}

void  CVehicle::PrintMaxWeight() {
    cout << "Max weight Vehicle can handle is: " << max_weight << "kg" << endl << endl;
}

CVehicle::CVehicle(double crub_weight_distance, double base_weight, double max_weight, double price_for_service, double real_weight) {

    if (real_weight > base_weight && real_weight < max_weight) {

        this->real_weight = real_weight;
        this->distance_with_weight = CalculateDistanceWithWeight(this->real_weight, crub_weight_distance);
        this->price_for_service = CalculatePriceForService(price_for_service);
        this->max_weight = CalculateMaxWeight(max_weight);
    }
    else {

        this->real_weight = base_weight;
        this->distance_with_weight = CalculateDistanceWithWeight(this->real_weight, crub_weight_distance);
        this->price_for_service = CalculatePriceForService(price_for_service);
        this->max_weight = CalculateMaxWeight(max_weight);
    }

}

double  CVehicle::CalculateDistanceWithWeight(double weight, double crub_weight_distance) {
    double loss_per_hundred_kg = crub_weight_distance / 1000;
    double distance_with_weight = crub_weight_distance - weight / 100 * loss_per_hundred_kg; // 18000 - 180 * 18

    return distance_with_weight;
}

double  CVehicle::CalculatePriceForService(double price_for_service) {
    return price_for_service;
}

double  CVehicle::CalculateMaxWeight(double max_weight) {
    return max_weight;
}
CVehicle::~CVehicle() {}
