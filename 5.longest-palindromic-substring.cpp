/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>
#include <iostream>

using namespace std;


// @lc code=start
class Solution {
public:



	string longestPalindrome(string s) {
		const int n = s.length();
		int start = 0;
		int size = 0;


		for(int i = 0; i < n; i++) {
			int len1 = expandFromMiddle(i, i, s);
			int len2 = expandFromMiddle(i, i + 1, s);
			int len = max(len1, len2);
			if(len > size) {
				start = i - ((len - 1) / 2);
				size = len;
			}
		}
		return s.substr(start, size);
	}

	int expandFromMiddle(int left, int right, string s) {
		while(left >= 0 && right < s.length() && s[left] == s[right]) {
			left--;
			right++;
		}
		return right - left - 1;
	}
};
// @lc code=end

