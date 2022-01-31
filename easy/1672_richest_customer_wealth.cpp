/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int max_wealth = INT_MIN;
		for(int i = 0; i < accounts.size(); i++) {
			int sum = 0;
			for(int j = 0; j < accounts[i].size(); j++) {
				sum += accounts[i][j];
			}

			max_wealth = max(max_wealth, sum);
		}

		return max_wealth;
	}
};
// @lc code=end

