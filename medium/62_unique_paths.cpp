/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
	// vector<int> fact_dp{ 1, 1 };
	// int fact(int n) {
	// 	if(n >= fact_dp.size())
	// 		fact_dp.push_back(n * fact(n - 1));

	// 	return fact_dp[n];
	// }
	// int comb(int n, int k) {
	// 	return fact(n) / (fact(n - k) * fact(k));
	// }

public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 1));

		for(int i = 1; i < m; i++)
			for(int j = 1; j < n; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

		return dp[m - 1][n - 1];
	}
};
// @lc code=end

