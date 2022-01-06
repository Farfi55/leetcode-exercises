// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem242.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
	bool isAnagram(string s, string t) {
		int n = s.length();
		int m = t.length();

		if(n != m) return false;

		int s_letters[26] = { 0 };
		int t_letters[26] = { 0 };

		for(int i = 0; i < n; i++) {
			s_letters[s[i] - 'a']++;
			t_letters[t[i] - 'a']++;
		}

		for(int i = 0; i < 26; i++)
			if(s_letters[i] != t_letters[i])
				return false;

		return true;
	}
};
// @lc code=end

