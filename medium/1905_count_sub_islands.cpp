#include <vector>
#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution {

	bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, unsigned i, unsigned j) {
		if(i >= grid1.size() || j >= grid1[0].size() || grid2[i][j] == 0)
			return true;

		// trasformo la terra in mare così da evitare di ripetere il calcolo
		// per la stessa
		grid2[i][j] = 0;

		// uso il bitwise & per accettarmi che vengano settati a 0
		// tutti i punti dell'isola
		// che essa sia sub-isola o meno
		return ((grid1[i][j] == 1) &
			(bfs(grid1, grid2, i + 1, j)) &
			(bfs(grid1, grid2, i, j + 1)) &
			(bfs(grid1, grid2, i - 1, j)) &
			(bfs(grid1, grid2, i, j - 1)));
	}


public:
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		const int m = grid1.size();
		const int n = grid1[0].size();

		int counter = 0;

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) {
				if(grid1[i][j] == 1 && grid2[i][j] == 1) {
					if(bfs(grid1, grid2, i, j)) {

						counter++;
					}
				}
			}

		return counter;

	}
};
// @lc code=end

int main() {
	vector<vector<int>> grid1 = { {1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1} };

	vector<vector<int>> grid2 = { {1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0} };

	auto out = Solution().countSubIslands(grid1, grid2);
	std::cout << out;
}
