/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int n_ = n - 1;
		vector<vector<int>> M(n, vector<int>(n));

		int val = 1;
		for(int i = 0; i * 2 < n; i++) {
			for(int j = i; j <= n_ - i; j++) M[i][j] = val++;
			for(int j = i + 1; j < n_ - i; j++) M[j][n_ - i] = val++;
			for(int j = i; j < n_ - i; j++) M[n_ - i][n_ - j] = val++;
			for(int j = i; j < n_ - i; j++) M[n_ - j][i] = val++;

		}
		return M;
	}
};
// @lc code=end

