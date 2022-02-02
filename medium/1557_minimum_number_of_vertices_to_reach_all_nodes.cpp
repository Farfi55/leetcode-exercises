/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

#include <vector>

using namespace std;


// @lc code=start
class Solution {
public:

	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		vector<bool> has_incoming_edge(n, false);

		for(vector<int>& edge : edges) {
			has_incoming_edge[edge[1]] = true;
		}

		vector<int> result;
		for(int i = 0; i < n; i++) {
			if(!has_incoming_edge[i])
				result.push_back(i);
		}

		return result;
	}
};
// @lc code=end

