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

		int i = 0;
		for(int reach = 0; i < n && i <= reach; ++i)
			reach = max(i + nums[i], reach);

		return i == n;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums = { 2,3,1,1,4 };

	cout << Solution().canJump(nums);

	return 0;
}
