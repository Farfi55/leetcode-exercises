/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		const int n = nums.size();
		int total = 0;
		int count = 0; // 1 because we ignore the first element 
		int curr_jump = INT_MIN;

		for(int i = 1; i < n; i++) {
			if(nums[i] - nums[i - 1] == curr_jump) {
				if(++count > 2)
					total += (count - 2);
			}
			else {
				count = 2;
				curr_jump = nums[i] - nums[i - 1];
			}
		}

		return total;
	}
};
// @lc code=end

