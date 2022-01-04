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
		int end = 0;
		int start = 0;
		int jumps = 0;

		while(end < n - 1) {

			int max_end = 0;
			for(int i = start; i <= end; i++)
				max_end = max(i + nums[i], max_end);

			start = end + 1;
			end = max_end;
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
