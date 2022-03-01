/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
class Solution {
public:
	int largestPerimeter(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());

		for(int i = 0; i < nums.size() - 2; i++) {
			if(nums[i] < nums[i + 1] + nums[i + 2])
				return nums[i] + nums[i + 1] + nums[i + 2];
		}
		return 0;
	}
};
// @lc code=end

