/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

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
		int n = costs.size() / 2;

		sort(costs.begin(), costs.end(), custom_sort);
		int tot = 0;
		for(int i = 0; i < n; i++) {
			tot += costs[i][0];
			tot += costs[i + n][1];
		}
		return tot;
	}
};
// @lc code=end

