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

		int jumps = nums[0];
		int i;
		for(i = 0; jumps && i < n; i++) {
			jumps = max(nums[i], jumps - 1);
		}
		return (i == n) || (n == 1);
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums = { 2,3,1,1,4 };

	cout << Solution().canJump(nums);

	return 0;
}
