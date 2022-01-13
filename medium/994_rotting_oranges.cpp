// @before-stub-for-debug-begin
#include <vector>
#include <queue>
#include <tuple>
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
		const size_t m = grid.size();
		const size_t n = grid[0].size();
		uint32_t max_time = m + n + 2;
		uint32_t last_orange = 2;
		uint32_t fresh_oranges = 0;

		queue<tuple<uint32_t, uint32_t, uint32_t>> q;

		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
				if(grid[i][j] != 0) {
					fresh_oranges++;
					if(grid[i][j] == 2) {
						// mark as fresh orange 
						// and then change the valaue back inside the while loop
						grid[i][j] = 1;
						q.push(make_tuple(i, j, 2));
					}
				}



		while(!q.empty()) {
			uint32_t i = get<0>(q.front());
			uint32_t j = get<1>(q.front());
			uint32_t time = get<2>(q.front());
			q.pop();

			if(i >= m || j >= n || grid[i][j] != 1) continue;

			grid[i][j] = time;
			last_orange = max(time, last_orange);
			fresh_oranges--;

			q.push(make_tuple(i + 1, j, time + 1));
			q.push(make_tuple(i - 1, j, time + 1));
			q.push(make_tuple(i, j + 1, time + 1));
			q.push(make_tuple(i, j - 1, time + 1));
		}

		// if there are oranges remaining, those will never rot, so we return -1
		// otherwise we return the time of rotting of the last orange
		return fresh_oranges ? -1 : last_orange - 2;

	}
};
// @lc code=end

