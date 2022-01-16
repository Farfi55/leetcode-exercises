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

		vector<vector<int>> dp(2, vector<int>(n + 1, 0));

		for(int i = m - 1; i >= 0; i--) {
			for(int j = n - 1; j >= 0; j--) {
				// i & 1 or (i+1)&1 basically alternates between 2 dp
				// arrays for every i, so we don't need to store m of them but just 2
				// (i & 1) its the same as writing (i % 2) for integers
				if(M[i][j] == '0')
					dp[i & 1][j] = 0;
				else // dp(i,j) = 1 + min(dp(i + 1, j), dp(i, j + 1), dp(i + 1, j + 1))
					dp[i & 1][j] = 1 + min(dp[(i + 1) & 1][j + 1], min(dp[i & 1][j + 1], dp[(i + 1) & 1][j]));
				max_sqr = max(max_sqr, dp[i & 1][j]);
			}
		}
		return max_sqr * max_sqr;
	}

};
// @lc code=end

