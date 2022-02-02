/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
class Solution {
public:
	vector<int> buildArray(vector<int>& nums) {
		vector<int> out(nums.size());

		for(int i = 0; i < nums.size(); i++) {
			out[i] = nums[nums[i]];
		}
		return out;
	}
};
// @lc code=end

