/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int colors[3] = {};
		for(int i = 0; i < nums.size(); i++) {
			colors[nums[i]]++;
		}

		for(int i = 0, j = 0; i < 3; i++) {
			while(colors[i]--)
				nums[j++] = i;
		}
	}
};
// @lc code=end

