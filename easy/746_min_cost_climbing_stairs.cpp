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
		int one_step_cost = cost[n - 2];
		int two_step_cost = cost[n - 1];
		int curr_cost = min(one_step_cost, two_step_cost);
		// f(i) = c(i) + min(f(i+1), f(i+2))

		for(int i = n - 3; i >= 0; --i) {
			two_step_cost = one_step_cost;
			one_step_cost = cost[i] + curr_cost;
			curr_cost = min(one_step_cost, two_step_cost);
		}

		return curr_cost;

	}
};
// @lc code=end
int main(int argc, char const* argv[])
{
	Solution sol;

	vector<int> cost = { 1, 100,   1,   1,   1, 100,   1,   1, 100,   1 };
	cout << sol.minCostClimbingStairs(cost);
	return 0;
}

