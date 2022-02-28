#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */


/*
[[0,0,1,1,0,1,0,0,1,0]
,[1,1,0,1,1,0,1,1,1,0]
,[1,0,1,1,1,0,0,1,1,0]
,[0,1,1,0,0,0,0,1,0,1]
,[0,0,0,0,0,0,1,1,1,0]
,[0,1,0,1,0,1,0,1,1,1]
,[1,0,1,0,1,1,0,0,0,1]
,[1,1,1,1,1,1,0,0,0,0]
,[1,1,1,0,0,1,0,1,0,1]
,[1,1,1,0,1,1,0,1,1,0]
]


*/
// @lc code=start
class Solution {
	void bfs(vector<vector<int>>& grid, unsigned row, unsigned col) {
		if(row >= grid.size() || col >= grid[0].size() || grid[row][col] == 1)
			return;


		grid[row][col] = 1;

		bfs(grid, row, col + 1);
		bfs(grid, row + 1, col);
		bfs(grid, row, col - 1);
		bfs(grid, row - 1, col);
	}

public:
	int closedIsland(vector<vector<int>>& grid) {
		unsigned counter = 0;
		unsigned m = grid.size();
		unsigned n = grid[0].size();

		// expand water from the (left, right) border
		for(int i = 1; i < m - 1; i++) {
			if(grid[i][0] == 0)
				bfs(grid, i, 0);

			if(grid[i][n - 1] == 0)
				bfs(grid, i, n - 1);
		}

		// expand water from the (top, bottom) border
		for(int i = 1; i < n - 1; i++) {
			if(grid[0][i] == 0)
				bfs(grid, 0, i);

			if(grid[m - 1][i] == 0)
				bfs(grid, m - 1, i);
		}


		// count the islands
		for(size_t i = 1; i < m - 1; i++)
			for(size_t j = 1; j < n - 1; j++)
				if(grid[i][j] == 0) {
					bfs(grid, i, j);
					counter++;
				}

		return counter;
	}
};
// @lc code=end


/*
{{0,0,1,0,0},
 {0,1,0,1,0},
 {0,1,1,1,0}}
*/

int main(int argc, char const* argv[])
{
	vector<vector<int>> grid = {
{0,0,1,0,0},
 {0,1,0,1,0},
 {0,1,1,1,0} };

		// {0, 0, 1, 1, 0, 1, 0, 0, 1, 0},
		// {1, 1, 0, 1, 1, 0, 1, 1, 1, 0},
		// {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
		// {0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
		// {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
		// {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
		// {1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
		// {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		// {1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
		// {1, 1, 1, 0, 1, 1, 0, 1, 1, 0} };

	auto counter = Solution().closedIsland(grid);
	std::cout << counter;
	return 0;
}

