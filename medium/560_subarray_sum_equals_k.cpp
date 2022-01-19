/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> sums;

		sums[0]++;
		int out = 0;
		int sum = 0;
		for(int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			out += sums[sum - k];
			sums[sum]++;
		}

		return out;
	}
};
// @lc code=end

