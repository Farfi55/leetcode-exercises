/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
	int getMinimoRaggiungibile(const vector<int> nums, vector<int> dp, int i) {
		int salti_min = INT_MAX - 1;
		for(int salto = 1; salto <= nums[i] && (i + salto) < nums.size(); salto++) {
			salti_min = min(salti_min, dp[i + salto]);
		}
		return salti_min;
	}
public:
	int jump(const vector<int>& nums) {

		int n = nums.size();
		vector<int> dp(n);

		dp[n - 1] = 0;
		for(int i = n - 2; i >= 0; --i) {
			dp[i] = 1 + getMinimoRaggiungibile(nums, dp, i);
		}

		return dp[0];
	}
};
// @lc code=end

