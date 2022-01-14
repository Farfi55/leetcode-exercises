#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
	int singleNumber(const vector<int>& nums) {
		int ret = 0;
		for(const int num : nums)
			ret ^= num;

		return ret;
	}
};
// @lc code=end

