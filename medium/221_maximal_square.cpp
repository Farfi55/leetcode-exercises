// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem221.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
	int maximalSquare(vector<vector<char>>& M) {
		int m = M.size();
		int n = M[0].size();

		int max_sqr = 0;

		vector<vector<int>> dp(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) {
				dp[i][j] = M[i][j] - '0';
				max_sqr = max(max_sqr, dp[i][j]);
			}

		for(int i = m - 2; i >= 0; i--) {
			for(int j = n - 2; j >= 0; j--) {
				if(dp[i][j])
					dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j]));
				max_sqr = max(max_sqr, dp[i][j]);
			}
		}
		return max_sqr * max_sqr;
	}

};
// @lc code=end

