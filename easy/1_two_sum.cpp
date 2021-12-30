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
		unordered_map<int, int> hash_map;

		for(int i = 0; i < n; i++) {
			int complement = target - nums[i];
			if(hash_map.find(complement) != hash_map.end())
				return vector<int>{ i, hash_map[complement] };
			hash_map[nums[i]] = i;
		}
		return vector<int>{-1, -1};
	}
};
// @lc code=end

