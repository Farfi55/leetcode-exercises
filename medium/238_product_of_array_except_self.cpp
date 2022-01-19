/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int total_prod = 1;
		int zeros = 0;

		for(int x : nums) {
			if(x == 0) zeros++;
			else total_prod *= x;
		}

		for(int i = 0; i < nums.size(); i++) {
			if(zeros > 1) nums[i] = 0;
			else if(zeros == 1) {
				if(nums[i]) nums[i] = 0;
				else nums[i] = total_prod;
			}
			else nums[i] = total_prod / nums[i];
		}

		return nums;
	}
};
// @lc code=end

