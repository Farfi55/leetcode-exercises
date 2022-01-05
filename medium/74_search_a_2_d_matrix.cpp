/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		const int n = matrix[0].size();
		const int N = n * matrix.size();
		int i = 0;
		int j = N - 1;

		while(i <= j) {
			int mid = (i + j) / 2;
			int val = matrix[mid / n][mid % n];

			if(val < target) i = mid + 1;
			else if(val > target) j = mid - 1;
			else return true;
		}
		return false;
	}
};
// @lc code=end

