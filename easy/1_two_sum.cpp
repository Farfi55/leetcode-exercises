/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		const int n = nums.size();
		unordered_map<int, int> indices;

		for(int i = 0; i < n; i++) {
			int complement = target - nums[i];
			if(indices.find(complement) != indices.end())
				return { i, indices[complement] };
			indices[nums[i]] = i;
		}
		return {};
	}
};
// @lc code=end

