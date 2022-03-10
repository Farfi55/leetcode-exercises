/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;
		unordered_set<int> set;

		for(int x : nums) {
			if(set.count(x)) return true;
			else set.insert(x);
		}

		return false;
	}
};
// @lc code=end

