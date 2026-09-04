#include "IsPerfect.h"

bool IsPerfect(int lcv) {
	int factorsum = 0;
	for (int i = 1; i < lcv; i++) {
		if (lcv % i == 0) {
			factorsum += i;
		}
	}

	if (factorsum == lcv) return true;
	return false;
}

int GetMaxValue(int argc, char* argv[]) {
	if (argc >= 2) return std::stoi(argv[1]);
	else {
		int maxVal;
		std::cout << "Input a Maximum Value for the Program: \n";
		std::cin >> maxVal;
		return maxVal;
	}
}
