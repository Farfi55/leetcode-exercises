/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		const int n = nums.size();
		if(n == 0) return 0;

		int prev = nums[0];
		int count = 1;
		for(int i = 1; i < n; i++) {
			if(nums[i] != prev) {
				prev = nums[count++] = nums[i];
			}
		}
		return count;
	}
};
// @lc code=end

