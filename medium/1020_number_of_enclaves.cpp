#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
	void bfs(vector<vector<int>>& grid, unsigned row, unsigned col, int* counter) {
		if(row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
			return;


		grid[row][col] = 0;

		if(counter)
			(*counter)++;


		bfs(grid, row, col + 1, counter);
		bfs(grid, row + 1, col, counter);
		bfs(grid, row, col - 1, counter);
		bfs(grid, row - 1, col, counter);
	}
public:
	int numEnclaves(vector<vector<int>>& grid) {
		int counter = 0;
		unsigned m = grid.size();
		unsigned n = grid[0].size();

		// expand water from the (left, right) border
		for(int i = 0; i < m; i++) {
			if(grid[i][0] == 1)
				bfs(grid, i, 0, nullptr);

			if(grid[i][n - 1] == 1)
				bfs(grid, i, n - 1, nullptr);
		}

		// expand water from the (top, bottom) border
		for(int i = 0; i < n; i++) {
			if(grid[0][i] == 1)
				bfs(grid, 0, i, nullptr);

			if(grid[m - 1][i] == 1)
				bfs(grid, m - 1, i, nullptr);
		}


		// count the islands
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
				if(grid[i][j] == 1) {
					bfs(grid, i, j, &counter);
				}

		return counter;
	}
};
// @lc code=end

/*
[[0,0,0,0],
 [1,0,1,0],
 [0,1,1,0],
 [0,0,0,0]]

*/
