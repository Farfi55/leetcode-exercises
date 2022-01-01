/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		const int n = nums.size();
		int max_sum = nums[0];
		int curr_sum = 0;

		for(int i = 0; i < n; i++) {
			curr_sum += nums[i];
			if(curr_sum > max_sum) max_sum = curr_sum;
			if(curr_sum < 0) curr_sum = 0;
		}
		return max_sum;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums;
	int x; cin >> x;
	while(x != 111) {
		nums.push_back(x);
		cin >> x;
	}
	cout << sol.maxSubArray(nums);
	return 0;
}

