// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem8.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
	int myAtoi(string s) {
		int n = s.length();
		int i = 0;

		int indicator = 1;
		int64_t out = 0;


		while(i < n && s[i] == ' ') i++;

		if(s[i] == '-' || s[i] == '+')
			indicator = (s[i++] == '-') ? -1 : 1;


		while('0' <= s[i] && s[i] <= '9') {
			out = out * 10 + (s[i++] - '0');
			if(out * indicator >= INT_MAX) return INT_MAX;
			if(out * indicator <= INT_MIN) return INT_MIN;
		}

		return indicator * out;

	}
};
// @lc code=end

