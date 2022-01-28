/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */
#include <array>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
	// https://www.wikiwand.com/en/Josephus_problem
	int findTheWinner(const int n, int k) {
		int res = 0;
		for(int i = 1; i <= n; ++i)
			res = (res + k) % i;
		return res + 1;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution().findTheWinner(5, 2);
	return 0;
}
