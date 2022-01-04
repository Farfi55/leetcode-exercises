/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>
#include <iostream>

using namespace std;

/*
		[2,3,0,1,4] IN

START: 	[0]
		reach = 0+2

JUMP 1: [2]

		reach = max(range(old_reach, new_reach))
		reach = max(1+3, 2+0) = 4

JUMP 2: [4]
		4 >= last_idx -> return JUMPS -> 2

*/


// @lc code=start
class Solution {
	int getMaxReach(const vector<int>& nums, int prev, int curr) {
		int max_reach = 0;
		for(int i = prev + 1; i <= curr; i++)
			max_reach = max(i + nums[i], max_reach);

		return max_reach;
	}
public:
	int jump(const vector<int>& nums) {
		int n = nums.size();
		if(n == 1) return 0;

		int curr_reach = nums[0];
		int prev_reach = 0;
		int jumps = 1;

		while(curr_reach < n - 1) {
			int new_reach = getMaxReach(nums, prev_reach, curr_reach);
			prev_reach = curr_reach;
			curr_reach = new_reach;

			jumps++;
		}
		return jumps;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	cout << Solution().jump(nums);
	return 0;
}
