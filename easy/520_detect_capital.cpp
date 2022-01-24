/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
	bool detectCapitalUse(string word) {
		uint8_t caps_letters = 0;
		uint8_t n_letters = word.length();

		for(char& c : word)
			if(c <= 'Z')
				caps_letters++;

		return (caps_letters == 0 // ||
			|| (caps_letters == n_letters) // ||
			|| (caps_letters == 1 && word[0] <= 'Z'));

	}
};
// @lc code=end

