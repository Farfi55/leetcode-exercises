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

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution {

	uint64_t uniquePaths(int m, int n) {

		// make sure that m >= n
		if(m < n) return uniquePaths(n, m);


		uint64_t res = 1;

		for(int i = m + 1, j = 1; j <= n; i++, j++) {
			res *= i;
			res /= j;
		}
		return res;
	}


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
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const size_t m = obstacleGrid.size();
		const size_t n = obstacleGrid[0].size();

		vector<pair<int, int>> obstacles;

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(obstacleGrid[i][j]) {
					if((i == 0 && j == 0) ||
						(i == m - 1 && j == n - 1))
						return 0;
					obstacles.push_back(make_pair(i, j));
				}


		uint64_t total = uniquePaths(m - 1, n - 1);

		for(int k = 0; k < obstacles.size();k++) {
			int i = obstacles[k].first;
			int j = obstacles[k].second;
			total -= uniquePaths(i, j) * uniquePaths(m - i - 1, n - j - 1);
		}

		return max((int)total, 0);
	}
};
// @lc code=end

