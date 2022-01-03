/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

#include <vector>
#include <queue>
#include <iostream>

using namespace std;


// @lc code=start
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int j = 0;

		for(int i = 0; i < n; i++) {
			if(nums[i] != 0)
				nums[j++] = nums[i];
		}
		while(j < n)
			nums[j++] = 0;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums = { 0, 1, 1, 0 };
	sol.moveZeroes(nums);
	for(int x : nums) cout << x << " ";
	return 0;
}
