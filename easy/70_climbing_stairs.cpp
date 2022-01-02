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
	int climbStairs(int n) {
		int ret = 0;
		int step_one = 1;
		int step_two = 0;

		for(int i = 0; i < n; ++i) {
			ret = step_one + step_two;
			step_two = step_one;
			step_one = ret;
		}

		return ret;
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

