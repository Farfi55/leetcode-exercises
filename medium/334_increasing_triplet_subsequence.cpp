/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int low_1 = INT_MAX;
		int low_2 = INT_MAX;

		for(int x : nums) {
			if(x <= low_1) low_1 = x;
			else if(x <= low_2) low_2 = x;
			else return true;
		}
		return false;
	}
};
// @lc code=end

