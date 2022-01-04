/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
/*
If you take a number, you might as well take them all.
Keep track of what the value is of the subset of the input
with maximum M when you either take or don't take M.
*/

// @lc code=start
class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		const int n = nums.size();
		const int MAX_VAL = 10000;

		vector<int> cnt(MAX_VAL + 1, 0);
		for(int i = 0;i < nums.size();i++) {
			cnt[nums[i]] += nums[i];
		}

		vector<int> dp(MAX_VAL + 1, 0);
		dp[1] = cnt[1]; // dp[1] since nums[i] >= 1
		dp[2] = max(cnt[1], cnt[2]);

		for(int i = 3; i <= MAX_VAL; i++) {
			dp[i] = max(dp[i - 1], cnt[i] + dp[i - 2]);
		}

		return dp[MAX_VAL];
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums = { 1, 3, 3, 2, 5, 5, 4, 6, 2 };
	Solution sol;
	cout << sol.deleteAndEarn(nums);
	return 0;
}
