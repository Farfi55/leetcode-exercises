/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
	static bool custom_sort(vector<int> a, vector<int> b) {
		return (a[1] - a[0]) > (b[1] - b[0]);
	}

	int twoCitySchedCost(vector<vector<int>>& costs) {
		int N = costs.size();
		int n = costs.size() / 2;

		// basically an heap
		priority_queue<pair<int, int>> pq;

		for(int i = 0; i < N; i++) {
			pq.push(make_pair(costs[i][0] - costs[i][1], i));
		}

		int tot = 0;
		for(int i = 0; i < n; i++) {
			tot += costs[pq.top().second][1];
			pq.pop();
		}
		for(int i = 0; i < n; i++) {
			tot += costs[pq.top().second][0];
			pq.pop();
		}
		return tot;
	}
};
// @lc code=end

