// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
// #include "commoncppproblem152.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int max_prod = nums[0];

		int curr_pos_prod = 1;
		int curr_neg_prod = 1;


		for(int i = 0; i < n; i++) {
			int val = nums[i];

			curr_neg_prod *= val;
			curr_pos_prod *= val;

			max_prod = max(curr_pos_prod, max_prod);
			max_prod = max(curr_neg_prod, max_prod);

			if(curr_neg_prod > curr_pos_prod)
				swap(curr_pos_prod, curr_neg_prod);

			if(curr_pos_prod <= 0)
				curr_pos_prod = max(1, curr_neg_prod);
			if(curr_neg_prod >= 0)
				curr_neg_prod = min(1, curr_pos_prod);

		}
		return max_prod;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums{ -3, -1, -1 };
	cout << Solution().maxProduct(nums);
	return 0;
}
