// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem221.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		int max_sqr = 0;
		for(int i = 0; i < m && max_sqr == 0; i++)
			for(int j = 0; j < n && max_sqr == 0; j++)
				if(matrix[i][j] - '0')
					max_sqr = 1;



		bool found_new_max = true;
		for(int sqr_size = 2; sqr_size <= min(n, m) && found_new_max; sqr_size++) {
			found_new_max = false;
			for(int i = 0; i <= m - sqr_size; i++) {
				for(int j = 0; j <= n - sqr_size; j++)
					if(matrix[i][j] - '0' == sqr_size - 1 // && 
						&& matrix[i + 1][j] - '0' == sqr_size - 1 // &&
						&& matrix[i][j + 1] - '0' == sqr_size - 1 // &&
						&& matrix[i + 1][j + 1] - '0' == sqr_size - 1) {
						matrix[i][j] = sqr_size + '0';
						max_sqr = sqr_size;
						found_new_max = true;
					}

			}

		}
		return max_sqr * max_sqr;
	}
};
// @lc code=end

