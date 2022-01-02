/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		const int n = nums.size();
		int i = 0;				// left pointer
		int j = n - 1;			// right pointer
		int k = n - 1;			// index of the return vector
		vector<int> out(n, 0);	// return vector

		while(k >= 0) {
			// if nums[i] is the biggest abs value
			if(abs(nums[i]) > abs(nums[j]))
				out[k--] = nums[i] * nums[i++]; // we use nums[i] for the next index
			else out[k--] = nums[j] * nums[j--]; // else we use nums[j]
		}
		return out;
	}
};
// @lc code=end

