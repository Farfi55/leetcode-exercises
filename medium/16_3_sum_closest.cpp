/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		const int n = nums.size();
		int closest = nums[0] + nums[1] + nums[n - 1];

		for(int i = 0; i < n; i++) {
			int left = i + 1;
			int right = n - 1;

			while(left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if(abs(target - sum) < abs(target - closest))
					closest = sum;

				if(sum < target) left++;
				else if(sum > target) right--;
				else return target;
			}
			// we skip to the next value for i
			while(i + 1 < n && nums[i] == nums[i + 1]) i++;
		}
		return closest;
	}
};
// @lc code=end

