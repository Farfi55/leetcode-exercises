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
		uint8_t upper_letters = 0;
		uint8_t total_letters = word.length();

		for(auto& c : word)
			if(isupper(c))
				upper_letters++;

		return (upper_letters == 0 // ||
			|| (upper_letters == total_letters) // ||
			|| (upper_letters == 1 && isupper(word[0])));

	}
};
// @lc code=end

