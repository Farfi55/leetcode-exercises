// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem304.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
	int m;
	int n;
	vector<vector<int>> sums;
public:
	NumMatrix(vector<vector<int>>& mat) :
		m(mat.size()), n(mat[0].size()), sums(m, vector<int>(n, 0)) {

		sums[0][0] = mat[0][0];
		for(int j = 1; j < n; j++)
			sums[0][j] = sums[0][j - 1] + mat[0][j];

		for(int i = 1; i < m; i++) {
			sums[i][0] = sums[i - 1][0] + mat[i][0];
			for(int j = 1; j < n; j++) {
				sums[i][j] = mat[i][j] +
					sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
			}
		}

	}


	int sumRegion(int row1, int col1, int row2, int col2) {
		col1--; row1--;
		return sums[row2][col2] // -
			- (col1 >= 0 ? sums[row2][col1] : 0) // -
			- (row1 >= 0 ? sums[row1][col2] : 0) // +
			+ ((col1 >= 0 && row1 >= 0) ? sums[row1][col1] : 0);
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

