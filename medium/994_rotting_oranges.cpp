// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem994.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

/*
[[2,0,1,1,1,1,1,1,1,1],
 [1,0,1,0,0,0,0,0,0,1],
 [1,0,1,0,1,1,1,1,0,1],
 [1,0,1,0,1,0,0,1,0,1],
 [1,0,1,0,1,0,0,1,0,1],
 [1,0,1,0,1,1,0,1,0,1],
 [1,0,1,0,0,0,0,1,0,1],
 [1,0,1,1,1,1,1,1,0,1],
 [1,0,0,0,0,0,0,0,0,1],
 [1,1,1,1,1,1,1,1,1,1]]

espected ans: 58
my ans: 27
*/

// @lc code=start
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		int max_time = m + n + 2;
		int last_orange = 2;


		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == 2) continue;
				if(grid[i][j] == 1) {
					int top = i - 1 >= 0 ? grid[i - 1][j] : 0;
					int left = j - 1 >= 0 ? grid[i][j - 1] : 0;
					if(left && top) grid[i][j] = min(left, top) + 1;
					else if(left) grid[i][j] = left + 1;
					else if(top) grid[i][j] = top + 1;
					else grid[i][j] = max_time;
				}
			}
		}

		for(int i = m - 1; i >= 0; --i) {
			for(int j = n - 1; j >= 0; --j) {
				if(grid[i][j] == 2 || grid[i][j] == 0) continue;
				else {
					int new_val;
					int bot = i + 1 < m ? grid[i + 1][j] : 0;
					int right = j + 1 < n ? grid[i][j + 1] : 0;
					if(right && bot) new_val = min(right, bot) + 1;
					else if(right) new_val = right + 1;
					else if(bot) new_val = bot + 1;
					else new_val = max_time;
					grid[i][j] = min(grid[i][j], new_val);
					last_orange = max(grid[i][j], last_orange);
				}
			}
		}
		return last_orange == max_time ? -1 : last_orange - 2;
	}
};
// @lc code=end

