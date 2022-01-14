// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem867.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		vector<vector<int>> out(n, vector<int>(m, 0));

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				out[j][i] = matrix[i][j];

		return out;
	}
};
// @lc code=end

