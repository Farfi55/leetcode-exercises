/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<int> fib_list = { 0, 1, 1 };

	int tribonacci(int n) {
		if(n >= fib_list.size())
			fib_list.push_back(tribonacci(n - 3) +
				tribonacci(n - 2) + tribonacci(n - 1));
		return fib_list[n];
	}
};
// @lc code=end

