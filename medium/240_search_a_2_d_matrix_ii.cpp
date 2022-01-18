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
	bool bin_search(vector<int>& arr, int target, int i, int j) {
		while(i <= j) {
			int mid = (i + j) / 2;

			if(target > arr[mid]) i = mid + 1;
			else if(target < arr[mid]) j = mid - 1;
			else return true;
		}
		return false;
	}
public:
	bool searchMatrix(vector<vector<int>>& M, int target) {
		int m = M.size();
		int n = M[0].size();


		int left = n - 1;

		while(left >= 0 && M[0][left] > target)
			--left;

		for(int i = 0; i < m; i++) {
			if(M[i][0] > target)
				return false;

			if(bin_search(M[i], target, 0, left))
				return true;
		}
		return false;
	}
};
// @lc code=end

