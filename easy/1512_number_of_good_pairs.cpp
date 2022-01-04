/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		vector<int> values_counter(101, 0);
		int pairs = 0;
		for(int i = 0; i < nums.size(); i++) {
			pairs += values_counter[nums[i]]++;
		}
		return pairs;
	}
};
// @lc code=end

