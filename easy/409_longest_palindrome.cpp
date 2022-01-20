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
		}


		for(int i = 0; i < 58; i++) {
			if(count[i] % 2) {
				odd++;
				lenght += count[i] - 1;
			}
			else lenght += count[i];
		}
		if(odd > 0)
			lenght += 1;
		return lenght;
	}
};
// @lc code=end

