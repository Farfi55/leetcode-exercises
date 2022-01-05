/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		const int n = nums.size();

		int tot_sum = 0;
		int sum_pos = 0;
		int sum_neg = 0;
		int max_sum = nums[0];
		int min_sum = nums[0];

		for(int& x : nums) {
			sum_pos = max(sum_pos + x, x);
			sum_neg = min(sum_neg + x, x);

			max_sum = max(sum_pos, max_sum);
			min_sum = min(sum_neg, min_sum);

			tot_sum += x;
		}

		if(tot_sum == min_sum) return max_sum;
		else return max(max_sum, tot_sum - min_sum);
	}
};
// @lc code=end

