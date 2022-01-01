/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;
		sort(nums.begin(), nums.end());	// O(nlog(n)) 

		for(int i = 0; i < n; i++)		// O(n)
			if(nums[i] == nums[i + 1])
				return true;

		return false;
	}
};
// @lc code=end

