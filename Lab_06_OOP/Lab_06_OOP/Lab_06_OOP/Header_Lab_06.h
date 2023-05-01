#pragma once
#include <iostream>
#include <string>

using namespace std;

class CVehicle {
public:
    void PrintName() {
        cout << "CVehicle\n\n";
    }

    double GetDistanceWithWeight() {
        return distance_with_weight;
    }
    double GetPriceForService() {
        return price_for_service;
    }
    double GetMaxWeight() {
        return max_weight;
    }

    void PrintDistanceWithWeight() {
        cout << "Max distance with weight of " << real_weight << "kg is: " << distance_with_weight << "km" << endl << endl;
    }
    void PrintPriceForService() {
        cout << "Price of service for 1000km is: $" << price_for_service << endl << endl;
    }
    void PrintMaxWeight() {
        cout << "Max weight Vehicle can handle is: " << max_weight << "kg" << endl << endl;
    }

    CVehicle(double crub_weight_distance, double base_weight, double max_weight, double price_for_service, double real_weight) {

        if (real_weight > base_weight && real_weight < max_weight) {

            this->real_weight = real_weight;
            this->distance_with_weight = CalculateDistanceWithWeight(real_weight, crub_weight_distance);
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
protected:

    double real_weight;
    double distance_with_weight;
    double price_for_service;
    double max_weight;
    double base_weight;
    string vehicle_name;

private:

    double CalculateDistanceWithWeight(double weight, double crub_weight_distance) {
        double loss_per_hundred_kg = crub_weight_distance / 1000;
        double distance_with_weight = crub_weight_distance - weight / 100 * loss_per_hundred_kg; // 18000 - 180 * 18

        return distance_with_weight;
    }
    double CalculatePriceForService(double price_for_service) {
        return price_for_service;
    }
    double CalculateMaxWeight(double max_weight) {
        return max_weight;
    }

};

class CCar : public CVehicle {
public:
    void PrintName() {
        cout << "CCar\n\n";
    }

    CCar() = delete;

    CCar(string vehicle_name, double additional_weigh = 0) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
        this->vehicle_name = vehicle_name;
    }

private:
    static double crub_weight_distance;
    static double max_weight;
    static double base_weight;
    static double price_for_service;

};

class CTruck : public CVehicle {
public:
    void PrintName() {
        cout << "CTruck\n\n";
    }

    CTruck() = delete;

    CTruck(string vehicle_name, double additional_weigh = 0) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
        this->vehicle_name = vehicle_name;
    }

private:
    static double crub_weight_distance;
    static double max_weight;
    static double base_weight;
    static double price_for_service;

};

class CMotorcycle : public CVehicle {
public:
    void PrintName() {
        cout << "CMotorcycle\n\n";
    }

    CMotorcycle() = delete;

    CMotorcycle(string vehicle_name, double additional_weigh = 0) : CVehicle(crub_weight_distance, base_weight, max_weight, price_for_service, additional_weigh) {
        this->vehicle_name = vehicle_name;
    }

private:
    static double crub_weight_distance;
    static double max_weight;
    static double base_weight;
    static double price_for_service;

};