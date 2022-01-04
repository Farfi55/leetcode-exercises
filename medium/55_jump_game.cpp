/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	bool canJump(vector<int>& nums) {
		const int n = nums.size();
		vector<bool> dp(n, false);

		dp[0] = true;
		for(int i = 0; i < n; i++) {
			if(!dp[i]) return false;

			for(int j = 1; j <= nums[i] && j + i < n; j++) {
				dp[i + j] = true;
			}
		}
		return dp[n - 1];
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums = { 2,3,1,1,4 };

	cout << Solution().canJump(nums);

	return 0;
}
