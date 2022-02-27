/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
	void bfs(vector<vector<char>>& grid, unsigned row, unsigned col) {
		if(row < grid.size() && col < grid[0].size() && grid[row][col] == '1') {
			grid[row][col] = '0';
			bfs(grid, row + 1, col);
			bfs(grid, row - 1, col);
			bfs(grid, row, col + 1);
			bfs(grid, row, col - 1);
		}
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int counter = 0;
		for(unsigned i = 0; i < grid.size(); i++)
			for(unsigned j = 0; j < grid[0].size(); j++)
				if(grid[i][j] == '1') {
					bfs(grid, i, j);
					counter++;
				}

		return counter;
	}
};
// @lc code=end

