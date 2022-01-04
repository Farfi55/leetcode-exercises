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
public:
	int jump(const vector<int>& nums) {
		int n = nums.size();
		if(n == 1) return 0;

		int i = nums[0];
		int prev_reach = 0;
		int jumps = 1;

		while(i < n - 1) {
			int new_reach = 0;
			for(int j = prev_reach + 1; j <= i; j++)
				new_reach = max(j + nums[j], new_reach);

			i = new_reach;
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
