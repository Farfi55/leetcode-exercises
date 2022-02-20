/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		const int n = s.length();
		vector<int> dp(n, 1);



		return dp[n - 1];
	}
};
// @lc code=end

