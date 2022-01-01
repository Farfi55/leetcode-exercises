/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<int> fib_list = { 0, 1 };

	int fib(int n) {
		if(n >= fib_list.size())
			fib_list.push_back(fib(n - 1) + fib(n - 2));

		return fib_list[n];
	}
};
// @lc code=end

