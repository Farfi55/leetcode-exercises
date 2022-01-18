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
	// bool bin_search(vector<int>& arr, int target, int i, int j) {
	// 	while(i <= j) {
	// 		int mid = (i + j) / 2;

	// 		if(target > arr[mid]) i = mid + 1;
	// 		else if(target < arr[mid]) j = mid - 1;
	// 		else return true;
	// 	}
	// 	return false;
	// }
public:
	bool searchMatrix(vector<vector<int>>& M, int target) {
		const auto m = M.size();

		int i = 0;
		int j = M[0].size() - 1;

		while(i < m && j >= 0) {
			// all elements in this colum are greater, skip column
			if(M[i][j] > target) j--;
			// remaining elements in this row are all less than target, skip row
			else if(M[i][j] < target) i++;
			// we found the target
			else return true;
		}
		return false;

	}
};
// @lc code=end

