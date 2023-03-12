#include "lab2.h"

double GetBoxVolume(double dSideA, double dSideB, double dHeight) {
	double result = NAN;
	if (dSideA >= 0 && dSideB >= 0 && dHeight >= 0) {

		result = dSideA * dSideB * dHeight;
	}

	return result;
}
