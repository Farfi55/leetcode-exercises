/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

	// @lc code=start
class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.length();
		vector<int> dp(n, 0);
		int max_valid = 0;

		for(int i = 1; i < n; i++) {
			if(s[i] == ')') {
				if(s[i - 1] == '(') { // ...()
					dp[i] = 2;
					if(i > 2)
						dp[i] += dp[i - 2];
				}
				else { // ...))
					int j = i - dp[i - 1] - 1;
					if(j >= 0 && s[j] == '(') { // ...((.valid.))
						dp[i] = dp[i - 1] + 2;
						if(j > 0)
							dp[i] += dp[j - 1];
					}
				}
				max_valid = max(max_valid, dp[i]);
			}
		}
		return max_valid;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	cout << sol.longestValidParentheses(")()(()))");
	return 0;
}
