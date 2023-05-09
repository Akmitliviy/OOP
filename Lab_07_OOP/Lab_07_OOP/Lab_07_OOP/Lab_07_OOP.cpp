#include "CVehicle.h"
#include "CCar.h"
#include "CTruck.h"
#include "CMotorcycle.h"

double CostOfTransportation(const vector<unique_ptr<CVehicle>>& list_of_vehicles, const double weight, const double distance) {

	double counter{ 0 };
	double cost{ 0 };
	bool isEnough{ false };
	double weight_left{ weight }, distanse_left{ distance };

	for (int i = 0; i < list_of_vehicles.size(); i++) {
		CCar* car = dynamic_cast<CCar*>(list_of_vehicles[i].get());
		CTruck* truck = dynamic_cast<CTruck*>(list_of_vehicles[i].get());
		CMotorcycle* motorcycle = dynamic_cast<CMotorcycle*>(list_of_vehicles[i].get());

		if (car) {
			if (car->GetDistanceWithWeight() < distance)
				continue;

			weight_left -= car->GetMaxWeight();
			cost += car->GetServicePricePerThousandKm() / 1000 * distance;

			counter++;
		}
		else if (truck) {
			if (truck->GetDistanceWithWeight() < distance)
				continue;

			weight_left -= truck->GetMaxWeight();
			cost += truck->GetServicePricePerThousandKm() / 1000 * distance;

			counter++;

		}
		else if (motorcycle) {
			if (motorcycle->GetDistanceWithWeight() < distance)
				continue;

			weight_left -= motorcycle->GetMaxWeight();
			cost += motorcycle->GetServicePricePerThousandKm() / 1000 * distance;

			counter++;

		}

		if (weight_left <= 0)
			return cost;

	}

	return 0;
}