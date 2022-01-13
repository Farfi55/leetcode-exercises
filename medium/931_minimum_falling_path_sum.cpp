// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem931.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		const int m = matrix.size();
		const int n = matrix[0].size();

		if(n == 1) {
			int sum = 0;
			for(int i = 0; i < m; i++) sum += matrix[i][0];
			return sum;
		}

		for(int i = m - 2; i >= 0; i--) {
			matrix[i][0] += min(matrix[i + 1][0], matrix[i + 1][1]);
			for(int j = 1; j + 1 < n; j++) {
				matrix[i][j] += min(matrix[i + 1][j - 1],
					min(matrix[i + 1][j], matrix[i + 1][j + 1]));
			}
			matrix[i][n - 1] += min(matrix[i + 1][n - 1], matrix[i + 1][n - 2]);
		}

		int min_path = INT_MAX;
		for(int i = 0; i < n; i++) {
			min_path = min(matrix[0][i], min_path);
		}

		return min_path;
	}
};
// @lc code=end

