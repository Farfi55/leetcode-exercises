/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <vector>

using namespace std;


// @lc code=start
class Solution {

	int lengthOfLIS(vector<int>& nums, int i, int prev) {
		if(i >= nums.size())
			return 0;
		else if(nums[i] > prev) {
			return max(1 + lengthOfLIS(nums, i + 1, nums[i]), lengthOfLIS(nums, i + 1, prev));
		}
		else
			return lengthOfLIS(nums, i + 1, prev);

		// if we dont pick the i-th num

	}

public:
	int lengthOfLIS(vector<int>& nums) {
		return lengthOfLIS(nums, 0, INT_MIN);
	}
};
// @lc code=end

