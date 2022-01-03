/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		const int n = numbers.size();
		int i = 0;
		int j = n - 1;

		while(i < j) {
			int sum = numbers[i] + numbers[j];
			if(sum > target) j--;
			else if(sum < target) i++;
			else return{ i + 1, j + 1 };
		}
		return {};
	}
};
// @lc code=end



int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums = { 5, 15, 75 };
	int target = 100;
	auto out = sol.twoSum(nums, target);
	if(!out.empty())
		cout << "[" << out[0] << ", " << out[1] << "]\n";
	return 0;
}

