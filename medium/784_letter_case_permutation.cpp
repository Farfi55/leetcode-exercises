// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem784.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution {
	void rec(string& s, int i, vector<string>& out) {
		if(i == s.length()) out.push_back(s);
		else if(s[i] > 64 && s[i] < 123) {
			rec(s, i + 1, out);
			s[i] ^= 0x20;
			rec(s, i + 1, out);
		}
		else rec(s, i + 1, out);
	}

public:
	vector<string> letterCasePermutation(string s) {
		vector<string> out;
		rec(s, 0, out);
		return out;
	}
};
// @lc code=end

