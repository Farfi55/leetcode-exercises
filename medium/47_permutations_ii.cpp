/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	void solve(int i, vector<int>& nums, vector<vector<int>>& permutations,
		vector<int>& current, int* available) {
		if(i == nums.size())
			permutations.push_back(current);
		else for(int j = 0; j < nums.size(); j++) {
			if(available[nums[j] + 10] > 0) {
				current.push_back(nums[j]);
				available[nums[j] + 10]--;
				solve(i + 1, nums, permutations, current, available);
				available[nums[j] + 10]++;
				current.pop_back();
			}
		}
	}

public:

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> permutations;
		vector<int> current; current.reserve(nums.size());
		int available[21] = { 0 };
		for(int num : nums) available[num]++;

		solve(0, nums, permutations, current, available);
		return permutations;
	}

};
// @lc code=end

int main(int argc, const char** argv) {
	Solution sol;
	vector<int> nums = { 1, 1, 2 };
	auto results = sol.permuteUnique(nums);

	for(vector<int> permutation : results) {
		for(int i = 0; i < nums.size(); i++)
			cout << permutation[i] << " ";
		cout << endl;
	}

	return 0;
}
