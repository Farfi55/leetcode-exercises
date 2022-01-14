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

		int sign = 1;
		// we use a 64bit int to check for overflows
		// comparing it with the max capacity of an int32
		int64_t result = 0;

		// we skip the leading spaces
		while(s[i] == ' ') i++;

		// check for a '-' or '+'
		if(s[i] == '-' || s[i] == '+')
			sign = (s[i++] == '-') ? -1 : 1;


		// iterate through all consequent digits
		// and stop at first non digit or end of string ('\0') 
		while('0' <= s[i] && s[i] <= '9') {
			result = result * 10 + (s[i++] - '0');
			if(result * sign >= INT_MAX) return INT_MAX;
			if(result * sign <= INT_MIN) return INT_MIN;
		}

		// at this point we know the result will fit in a int32  
		return result * sign;

	}
};
// @lc code=end

