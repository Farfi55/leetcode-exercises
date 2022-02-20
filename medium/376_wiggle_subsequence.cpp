/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		const int n = nums.size();
		if(n < 2) return n;


		// [1, 1, 7,  4,  9, 2, 5]
		//   0,  6, -3, 5, -7, 3


		int up = 1;
		int down = 1;

		for(int i = 1; i < n; i++) {
			if(nums[i] > nums[i - 1]) {
				up = down + 1;
			}
			else if(nums[i] < nums[i - 1]) {
				down = up + 1;
			}
		}

		return max(up, down);
	}
};
// @lc code=end

