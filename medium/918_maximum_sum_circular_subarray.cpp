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

		int max_sum = INT_MIN;
		int min_sum = INT_MAX;

		for(int i = 0; i < n; i++) {
			int val = nums[i];
			sum_pos += val;
			sum_neg += val;
			tot_sum += val;

			max_sum = max(sum_pos, max_sum);
			min_sum = min(sum_neg, min_sum);

			if(sum_pos < 0) sum_pos = 0;
			if(sum_neg > 0) sum_neg = 0;
		}

		if(tot_sum == min_sum) return max_sum;
		else return max(max_sum, tot_sum - min_sum);
	}
};
// @lc code=end

