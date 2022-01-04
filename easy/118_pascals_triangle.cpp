/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		int cols = 1;

		vector<vector<int>> out(numRows);
		for(int i = 0; i < numRows; i++) {
			out[i] = vector<int>(i + 1, 1);

			for(int j = 1; j < i; j++)
				out[i][j] = out[i - 1][j - 1] + out[i - 1][j];

		}
		return out;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	auto out = Solution().generate(5);

	for(auto row : out) {
		for(int x : row)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}

