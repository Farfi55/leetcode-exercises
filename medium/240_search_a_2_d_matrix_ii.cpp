// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem240.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
	bool bin_search(vector<int>& arr, int target) {
		int i = 0;
		int j = arr.size() - 1;


		while(i <= j) {
			int mid = (i + j) / 2;

			if(target > arr[mid]) i = mid + 1;
			else if(target < arr[mid]) j = mid - 1;
			else return true;
		}
		return false;
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		for(int i = 0; i < m; i++) {
			if(matrix[i][0] > target)
				return false;

			if(target <= matrix[i][n - 1] &&
				bin_search(matrix[i], target))
				return true;

		}
		return false;
	}
};
// @lc code=end

