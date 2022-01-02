/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <vector>
#include <iostream>

using namespace std;



// @lc code=start
class Solution {
public:
/*
n: 8
	  0   1   2	  3	  4	  5	  6	  7
	[ -,  -,  -,  -,  -,  -,  -,  1,  1]
	[ -,  -,  -,  -,  -,  -,  2,  1,  1]
	[ -,  -,  -,  -,  -,  3,  2,  1,  1]
	[ -,  -,  -,  -,  5,  3,  2,  1,  1]
	[ -,  -,  -,  8,  5,  3,  2,  1,  1]
	[ -,  -, 13,  8,  5,  3,  2,  1,  1]
	[ -, 21, 13,  8,  5,  3,  2,  1,  1]
	[34, 21, 13,  8,  5,  3,  2,  1,  1]

*/


	int climbStairs(int n) {
		vector<int> dp(n + 1, 0);
		dp[n - 1] = dp[n] = 1;

		for(int i = n - 2; i >= 0; --i) {
			dp[i] = dp[i + 1] + dp[i + 2];
		}

		return dp[0];
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	int x; cin >> x;
	cout << sol.climbStairs(x);
	return 0;
}

