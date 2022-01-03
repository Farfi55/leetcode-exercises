/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */


#include <vector>
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
	// dp[i] = max{ dp[i+1], W[i] + dp[i+2] } 

	int rob(vector<int>& nums, int i, vector<int>& dp) {
		if(i >= nums.size()) return 0;
		if(dp[i] != -1) return dp[i];
		dp[i] = max(rob(nums, i + 1, dp), nums[i] + rob(nums, i + 2, dp));
		return dp[i];
	}

public:
	int rob(vector<int>& nums) {
		const int n = nums.size();

		if(n == 1) return nums[0];

		int prev2 = nums[0];
		int prev = max(nums[0], nums[1]);
		int robbed = prev;

		for(int i = 2; i < n; i++) {
			robbed = max(prev, nums[i] + prev2);
			prev2 = prev;
			prev = robbed;
		}
		return robbed;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	// vector<int> houses = { 2, 1, 1, 2 };
	vector<int> houses = { 1, 2, 3, 1 };
	Solution sol;
	cout << sol.rob(houses);
	return 0;
}

