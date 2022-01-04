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

	void rec(vector<int>& nums, vector<bool>& dp, int i) {
		dp[i] = true;
		for(int j = 1; j <= nums[i] && j + i < nums.size(); j++) {
			if(!dp[i + j])
				rec(nums, dp, i + j);
		}
	}
public:
	bool canJump(vector<int>& nums) {
		const int n = nums.size();
		vector<bool> dp(n, false);

		rec(nums, dp, 0);

		return dp[n - 1];
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums = { 3,0,8,2,0,0,1 };

	cout << Solution().canJump(nums);

	return 0;
}
