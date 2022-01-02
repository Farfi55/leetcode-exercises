/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
/*
	[  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
	[  -,   -,   -,   -,   -,   -,   -,   -, 100,   1]
	[  -,   -,   -,   -,   -,   -,   -,   2, 100,   1]
	[  -,   -,   -,   -,   -,   -,   3,   2, 100,   1]
	[  -,   -,   -,   -,   -, 102,   3,   2, 100,   1]
	[  -,   -,   -,   -,   4, 102,   3,   2, 100,   1]
	[  -,   -,   -,   5,   4, 102,   3,   2, 100,   1]
	[  -,   -,   5,   5,   4, 102,   3,   2, 100,   1]
	[  -, 105,   5,   5,   4, 102,   3,   2, 100,   1]
	[  6, 105,   5,   5,   4, 102,   3,   2, 100,   1]



*/
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();

		for(int i = n - 3; i >= 0; --i) {
			cost[i] += min(cost[i + 1], cost[i + 2]);
		}

		return min(cost[0], cost[1]);

	}
};
// @lc code=end
int main(int argc, char const* argv[])
{
	Solution sol;

	vector<int> cost = { 10, 15, 20 };
	cout << sol.minCostClimbingStairs(cost);
	return 0;
}

