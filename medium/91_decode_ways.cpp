// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem91.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */


// @lc code=start
class Solution {
public:
	int numDecodings(string s) {
		const int n = s.length();

		int prev = 1;
		int prev2 = 0;

		for(int i = n - 1; i >= 0; --i) {
			int	curr = (s[i] == '0') ? 0 : prev;

			if(i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
				curr += prev2;

			prev2 = prev;
			prev = curr;
		}
		return prev;
	}

};
// @lc code=end

