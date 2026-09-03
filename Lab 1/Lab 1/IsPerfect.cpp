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

bool IsWeird(int lcv) {
	std::vector<int> factors;

	int count = 0;

	int factorsum = 0;
	for (int i = 1; i < lcv; i++) {
		if (lcv % i == 0) {
			factorsum += i;
			factors.push_back(i);
		}
	}
	if (factorsum <= lcv) return false;

	if (check_sum(factors, lcv)[0] != -1) return false;
	
	return true;
}

std::vector<int> check_sum(std::vector<int> nums, int lcv) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	if (sum == lcv) return nums;
	if (nums.size() == 1) return { -1 };
	for (int i = 0; i < nums.size(); i++) {
		int tempval = nums[i];
		nums.erase(nums.begin() + i);
		std::vector<int> temp = nums;
		nums.push_back(tempval);
		std::vector<int> newfactors = check_sum(temp, lcv);
		if (newfactors[0] != -1) {
			return newfactors;
		}
	}
	return { -1 };
}