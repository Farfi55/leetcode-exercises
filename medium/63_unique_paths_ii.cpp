// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem63.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const size_t m = obstacleGrid.size();
		const size_t n = obstacleGrid[0].size();

		vector<int> dp(n, 0);
		dp[0] = 1;

		for(size_t i = 0; i < m; i++) {
			dp[0] = min(dp[0], 1 - obstacleGrid[i][0]);
			for(size_t j = 1; j < n; j++) {
				if(!obstacleGrid[i][j])
					dp[j] += dp[j - 1];
				else dp[j] = 0;
			}
		}

		return dp[n - 1];
	}
};
// @lc code=end
