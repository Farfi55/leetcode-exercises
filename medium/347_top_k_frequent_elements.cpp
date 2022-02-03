/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> frequencies;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;


		for(int x : nums) frequencies[x]++;

		for(const auto& frequence : frequencies) {
			heap.emplace(frequence.second, frequence.first);
			while(heap.size() > k)
				heap.pop();
		}

		vector<int> out; out.reserve(k);

		for(int i = 0; i < k; i++) {
			out.push_back(heap.top().second);
			heap.pop();
		}

		return out;
	}
};
// @lc code=end

