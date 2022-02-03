/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> frequencies;

		for(int x : nums) {
			frequencies[x]++;
		}

		vector<pair<int, int>> elems;

		for(auto pair_ : frequencies) {
			elems.emplace_back(pair_.second, pair_.first);
		}

		sort(elems.begin(), elems.end());

		vector<int> result;

		for(int i = 1; i <= k; i++)
			result.push_back(elems[elems.size() - i].second);

		return result;

	}
};
// @lc code=end

