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
	int uniquePathsWithObstacles(vector<vector<int>>& grid) {
		const size_t m = grid.size();
		const size_t n = grid[0].size();

		if(grid[0][0] || grid[m - 1][n - 1])
			return 0;


		grid[0][0] = 1;

		for(size_t j = 1; j < n; j++)
			grid[0][j] = grid[0][j] ? 0 : grid[0][j - 1];

		for(size_t i = 1; i < m; i++) {
			grid[i][0] = grid[i][0] ? 0 : grid[i - 1][0];

			for(size_t j = 1; j < n; j++) {
				grid[i][j] = grid[i][j] ? 0 : grid[i - 1][j] + grid[i][j - 1];
			}
		}

		return grid[m - 1][n - 1];
	}
};
// @lc code=end
