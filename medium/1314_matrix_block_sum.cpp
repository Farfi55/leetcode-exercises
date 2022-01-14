/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

#include <vector>
#include <iostream>

using namespace std;

/*
	[1, 2, 3]
	[4, 5, 6]
	[7, 8, 9]

con k = 1
	[12, 21, 16]
	[27, 45, 33]
	[24, 39, 28]

con k = 2
	[45, 45, 45]
	[45, 45, 45]
	[45, 45, 45]
*/
// @lc code=start

class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();

		vector<int> row_sum(m, 0);
		vector<int> col_sum(n, 0);
		int tot_sum = 0;

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				row_sum[i] += mat[i][j];
				col_sum[j] += mat[i][j];
				tot_sum += mat[i][j];
			}
		}

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				mat[i][j] = 0;
				for(int l = -k; l <= k; l++) {
					if(0 <= i + l && i + l < m)
						mat[i][j] += row_sum[i + l];
					if(0 <= j + l && j + l < n)
						mat[i][j] += col_sum[j + l];
				}
			}
		}
		return mat;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<vector<int>> mat{ {1, 2, 3},
							 {4, 5, 6},
							 {7, 8, 9} };
	auto out = Solution().matrixBlockSum(mat, 1);

	for(vector<int>& row : out) {
		for(int x : row) {
			cout << x << " ";
		}

		cout << '\n';
	}


	return 0;
}
