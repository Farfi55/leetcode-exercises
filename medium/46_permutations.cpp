/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
	void solve(int i, vector<int>& nums, vector<vector<int>>& permutations,
		vector<int>& current, bool* used) {
		if(i == nums.size())
			permutations.push_back(current);
		else for(int j = 0; j < nums.size(); j++) {
			if(!used[nums[j] + 10]) {
				current.push_back(nums[j]);
				used[nums[j] + 10] = true;
				solve(i + 1, nums, permutations, current, used);
				used[nums[j] + 10] = false;
				current.pop_back();
			}
		}


	}


public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> permutations;
		vector<int> current; current.reserve(nums.size());
		bool used[21] = { 0 };
		solve(0, nums, permutations, current, used);
		return permutations;
	}
};
// @lc code=end

