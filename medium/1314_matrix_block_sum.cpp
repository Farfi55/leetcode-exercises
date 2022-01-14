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

	[ 1,  3,  6]
	[ 5, 12, 21]
	[12, 27, 45]




[1, 2, 3, 3]
[7, 1, 2, 5]
[4, 5, 6, 8]
[7, 8, 9, 2]






*/



// @lc code=start

class Solution {
	int get(vector<vector<int>>& sums, int i, int j) {
		if(i < 0 || j < 0) return 0;

		i = min(i, int(sums.size()) - 1);
		j = min(j, int(sums[0].size()) - 1);

		return sums[i][j];
	}

public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();

		vector<vector<int>> sums(m, vector<int>(n, 0));

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

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				mat[i][j] = get(sums, i + k, j + k) // -
					- get(sums, i - k - 1, j + k) - get(sums, i + k, j - k - 1) // +
					+ get(sums, i - k - 1, j - k - 1);
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
