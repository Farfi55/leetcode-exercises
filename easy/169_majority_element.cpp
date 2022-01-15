/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int n = nums.size() / 2;
		unordered_map<int, int> occurrences;

		for(int num : nums) {
			if(++occurrences[num] > n)
				return num;
		}

		// just to compile
		return nums[0];
	}
};
// @lc code=end

