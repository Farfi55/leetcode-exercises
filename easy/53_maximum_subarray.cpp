/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		const int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		int max_sum = nums[0];

		for(int i = 0; i < n; i++) {
			max_sum = max(nums[i], max_sum);
			dp[i][i] = nums[i];
		}

		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n - i; j++) {
				int sum = dp[j][i + j - 1] + dp[i + j][i + j];
				max_sum = max(sum, max_sum);
				dp[j][i + j] = sum;
			}
		}
		return max_sum;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums;
	int x; cin >> x;
	while(x != 13131) {
		nums.push_back(x);
		cin >> x;
	}
	cout << sol.maxSubArray(nums);
	return 0;
}

