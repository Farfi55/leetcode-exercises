// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem695.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {

	int dfs(vector<vector<int>>& grid, int i, int j) {
		if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
			return 0;

		if(!grid[i][j])
			return 0;

		grid[i][j] = false;


		return 1 +
			dfs(grid, i + 1, j) +
			dfs(grid, i - 1, j) +
			dfs(grid, i, j + 1) +
			dfs(grid, i, j - 1);
	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int max_island_size = 0;
		int m = grid.size();
		int n = grid[0].size();

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(grid[i][j])
					max_island_size = max(dfs(grid, i, j), max_island_size);


		return max_island_size;
	}
};
// @lc code=end

