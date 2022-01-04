/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */
#include <vector>
#include <iostream>

using namespace std;


// @lc code=start
class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		const int m = mat.size();
		const int n = mat[0].size();
		if(n * m != r * c) return mat;

		vector<vector<int>> out(r, vector<int>(c, 0));

		// mat[m][n] -> m = (idx/m), n = (idx%m)
		// out[r][c] -> r = (idx/r), c = (idx%r)

		const int N = n * m;
		for(int i = 0; i < N; i++)
			out[i / c][i % c] = mat[i / n][i % n];

		return out;
	}
};
// @lc code=end

