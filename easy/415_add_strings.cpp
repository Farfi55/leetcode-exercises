/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	string addStrings(string num1, string num2) {
		int n1 = num1.length();
		int n2 = num2.length();
		if(n1 == 0) return num2;
		if(n2 == 0) return num1;

		string out;
		int carry = 0;
		for(int i = 0; i <= max(n1, n2); i++) {

			char add1 = i < n1 ? num1[n1 - 1 - i] : '0';
			char add2 = i < n2 ? num2[n2 - 1 - i] : '0';
			char num = (add1 + add2 + carry) - '0';
			if(num > '9') {
				carry = 1;
				num -= 10;
			}
			else carry = 0;
			if(i != max(n1, n2) || num != '0')
				out = num + out;
		}
		return out;

	}
};
// @lc code=end

