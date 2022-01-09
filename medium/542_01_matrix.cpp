// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <tuple>
// #include "commoncppproblem542.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int m = mat.size();
		int n = mat[0].size();
		int LIM = n + m;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(mat[i][j]) {
					int top = LIM, left = LIM;
					if(i - 1 >= 0) top = mat[i - 1][j];
					if(j - 1 >= 0) left = mat[i][j - 1];
					mat[i][j] = min(top, left) + 1;
				}
			}
		}
		for(int i = m - 1; i >= 0; i--) {
			for(int j = n - 1; j >= 0; j--) {
				if(mat[i][j]) {
					int bot = LIM, right = LIM;
					if(i + 1 < m) bot = mat[i + 1][j];
					if(j + 1 < n) right = mat[i][j + 1];
					mat[i][j] = min(mat[i][j], min(bot, right) + 1);
				}
			}
		}
		return mat;
	}
};
// @lc code=end

