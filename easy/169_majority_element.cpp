/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <unordered_map>
#include <vector>

using namespace std;

// https://www.wikiwand.com/en/Boyer%E2%80%93Moore_majority_vote_algorithm

// @lc code=start
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0;
		int major = nums[0];

		for(int num : nums) {
			if(count == 0) {
				major = num;
				count++;
			}
			else if(num == major)
				count++;
			else count--;
		}

		return major;
	}
};
// @lc code=end

