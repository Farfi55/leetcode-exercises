/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// last index char i appared in the string
		// -1 implies never (for now)
		vector<int> character_at(128, -1);
		int max_lenght = 0;
		int current_lenght = 0;

		for(int i = 0; i < s.size(); i++) {
			const unsigned char c = s[i];

			current_lenght = min(current_lenght + 1, i - character_at[c]);

			character_at[c] = i;

			max_lenght = max(current_lenght, max_lenght);
		}

		return max_lenght;

	}
};
// @lc code=end

