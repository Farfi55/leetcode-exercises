// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem300.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


// @lc code=start
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();

		vector<int> dp(n, 1);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < i; ++j)
				if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;

		return *max_element(dp.begin(), dp.end());
	}
};
// @lc code=end

