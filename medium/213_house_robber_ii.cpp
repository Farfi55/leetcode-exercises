/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
Since House[1] and House[n] are adjacent,
they cannot be robbed together.

Therefore, the problem becomes to rob either
House[1]-House[n-1] or House[2]-House[n],
depending on which choice offers more money.

Now the problem has degenerated to the House Robber,
which is already been solved.
*/
// @lc code=start
class Solution {

	int rob(vector<int>& nums, int start, int end) {
		int prev = 0, prev2 = 0;
		int robbed = 0;

		for(int i = start; i < end; i++) {
			robbed = max(prev, nums[i] + prev2);
			prev2 = prev;
			prev = robbed;
		}
		return robbed;
	}

public:
	int rob(vector<int>& nums) {
		const int n = nums.size();
		if(n == 1) return nums[0];

		return max(rob(nums, 0, n - 1), rob(nums, 1, n));
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	// vector<int> houses = { 2, 1, 1, 2 };
	vector<int> houses = { 1, 2, 3, 1 };
	Solution sol;
	cout << sol.rob(houses);
	return 0;
}

