#ifndef __IsWeird_H__
#define __IsWeird_H__

#include <vector>
#include <string>


bool IsWeird(int lcv);
std::vector<int> check_sum(std::vector<int> nums, int lcv);
bool optimized_check_sum(std::vector<int>& nums, int current_sum, int index, int lcv);

#endif // __IsWeird_H__