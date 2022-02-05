// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem973.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

		for(auto& point : points) {
			int x = point[0];
			int y = point[1];
			int dist = x * x + y * y;
			pq.emplace(dist, x, y);
		}

		vector<vector<int>> out;
		for(int i = 0; i < k; i++) {
			out.push_back({ get<1>(pq.top()), get<2>(pq.top()) });
			pq.pop();
		}

		return out;
	}
};
// @lc code=end

