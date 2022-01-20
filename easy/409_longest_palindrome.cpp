/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	int longestPalindrome(string s) {
		int count[58] = { 0 };

		int lenght = 0;
		int odd = 0;
		for(const char& c : s) {
			count[c - 'A']++;
			if(count[c - 'A'] & 1) odd++;
			else {
				lenght += 2;
				odd--;
			}
		}

		return odd > 0 ? lenght + 1 : lenght;
	}
};
// @lc code=end

