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
public:
	int rob(vector<int>& nums) {
		const int n = nums.size();
		if(n == 1) return nums[0];
		if(n == 2) return max(nums[0], nums[1]);
		if(n == 3) return max(nums[0], max(nums[1], nums[2]));

		int prev = 0, prev2 = 0;
		int robbed = 0;

		bool chose_first = (nums[0] + nums[n - 2] > nums[1] + nums[n - 1]);


		for(int i = 0; i < n - 1; i++) {
			robbed = max(prev, nums[i] + prev2);
			prev2 = prev;
			prev = robbed;
		}
		int robbery_1 = robbed;

		robbed = 0;
		prev = 0;
		prev2 = 0;

		for(int i = 1; i < n; i++) {
			robbed = max(prev, nums[i] + prev2);
			prev2 = prev;
			prev = robbed;
		}


		return max(robbery_1, robbed);
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

