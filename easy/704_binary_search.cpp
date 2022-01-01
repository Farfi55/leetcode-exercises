/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include <vector>
#include <iostream>
using namespace std;


// @lc code=start
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while(left <= right) {
			int middle = (left + right) / 2;
			if(target < nums[middle]) right = middle - 1;
			else if(target > nums[middle]) left = middle + 1;
			else return middle; // (target == nums[middle])
		}
		return -1;
	}
};
// @lc code=end


int main() {
	Solution sol;
	auto nums = vector<int>{ -1, 0, 5 };
	cout << sol.search(nums, -1);
	return 0;
}
