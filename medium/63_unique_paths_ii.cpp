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

/*

	. . . . .
	. . . . .
	. * . . .
	. . . . .

	+-+ . . .
	| | . . .
	+-+-----+
	. +-----+

	[0,0,0,0],
	[0,1,0,0],
	[0,0,0,0],
	[0,0,1,0],
	[0,0,0,0]

	. . . .
	. * . .
	. . . .
	. . * .
	. . . .

	+-+ . .
	+-+---+
	. | . |
	. | * |
	. +---+

	+---+ .
	| * | .
	| . | .
	+---+-+
	. . +-+

	+-+ . .
	+-+-+ .
	. | | .
	. +-+-+
	. . +-+


*/

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const size_t m = obstacleGrid.size();
		const size_t n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 1));


		dp[0][0] = 1 - obstacleGrid[0][0];
		for(int j = 1; j < n; j++)
			dp[0][j] = min(1 - obstacleGrid[0][j], dp[0][j - 1]);

		for(int i = 1; i < m; i++) {
			dp[i][0] = min(1 - obstacleGrid[i][0], dp[i - 1][0]);
			for(int j = 1; j < n; j++) {
				if(!obstacleGrid[i][j])
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				else dp[i][j] = 0;
			}
		}

		return dp[m - 1][n - 1];
	}


};
// @lc code=end

