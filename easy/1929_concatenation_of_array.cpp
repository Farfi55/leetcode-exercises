/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
public:
	vector<int> getConcatenation(vector<int>& nums) {
		const int n = nums.size();
		nums.reserve(2 * n);

		for(int i = 0; i < n; i++)
			nums.push_back(nums[i]);

		return nums;
	}
};
// @lc code=end

