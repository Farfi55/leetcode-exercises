// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem48.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
	void rotate(vector<vector<int>>& M) {
		int m = M.size();
		int n = M.size() - 1;

		// outer loop, starts from the biggest
		// square and srinks to a square
		for(int i = 0; i * 2 < n; i++) {
			for(int j = i; j < n - i; j++) {
				int tmp = M[i][j];
				M[i][j] = M[n - j][i];
				M[n - j][i] = M[n - i][n - j];
				M[n - i][n - j] = M[j][n - i];
				M[j][n - i] = tmp;
			}
		}
	}
};
// @lc code=end

