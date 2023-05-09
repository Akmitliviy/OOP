#include <iostream>

using namespace std;

int main() {
	int sum = 6;
	for (int i = 0; i < 2; i++) {
		if (i == 0)
			sum += 3;
		else
			sum -= 3;

		for (int j = 0; j < 2; j++) {
			if (j == 0)
				sum += 4;
			else
				sum -= 4;

			for (int k = 0; k < 2; k++) {
				if (k == 0)
					sum += 2;
				else
					sum -= 2;

				for (int l = 0; l < 2; l++) {

					if (l == 0)
						sum += 6;
					else
						sum -= 6;

						cout << "Result is " << sum << "\n\n";
						cout << "i = " << i << endl;
						cout << "j = " << j << endl;
						cout << "k = " << k << endl;
						cout << "l = " << l << endl;
						cout << endl << endl << endl << endl;

						if (l == 0)
							sum -= 6;
						else
							sum += 6;

				}
				if (k == 0)
					sum -= 2;
				else
					sum += 2;
			}
			if (j == 0)
				sum -= 4;
			else
				sum += 4;
		}
		if (i == 0)
			sum -= 3;
		else
			sum += 3;
	}

	return 0;
}