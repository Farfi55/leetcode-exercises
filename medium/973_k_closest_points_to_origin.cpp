/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <unordered_map>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {



		sort(points.begin(), points.end(), [](const auto& l, const auto& r) {
			return (l[0] * l[0] + l[1] * l[1]) < (r[0] * r[0] + r[1] * r[1]);
			});

		while(points.size() > k)
			points.pop_back();

		return points;
	}
};
// @lc code=end

