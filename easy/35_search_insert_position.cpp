/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while(left <= right) {
			int middle = (left + right) / 2;
			if(target < nums[middle]) right = middle - 1;
			else if(target > nums[middle]) left = middle + 1;
			else return middle; // (target == nums[middle])
		}
		// this return is the only thing that differs 
		// from a normal binary search
		return left;
	}
};
// @lc code=end

