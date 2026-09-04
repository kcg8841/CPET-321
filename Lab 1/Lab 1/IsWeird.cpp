#include "IsWeird.h"


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

	return !optimized_check_sum(factors, 0, 0, lcv);
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

bool optimized_check_sum(std::vector<int>& nums, int current_sum, int index, int lcv) {
	if (index >= nums.size()) return false;
	
	int new_sum = current_sum + nums[index];
	if (new_sum > lcv) return false;

	if (new_sum == lcv) return true;
	
	if (optimized_check_sum(nums, new_sum, index + 1, lcv)) return true;
	
	return optimized_check_sum(nums, current_sum, index + 1, lcv);
}