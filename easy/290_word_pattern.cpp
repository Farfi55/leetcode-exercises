// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
// #include "commoncppproblem290.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		int p_len = pattern.length();
		string map[26] = {};

		size_t start = 0;
		for(int i = 0; i < p_len; i++) {
			size_t space = s.find(' ', start);
			string word = s.substr(start, space - start);

			if(map[pattern[i] - 'a'] == "") {
				for(int j = 0; j < 26; j++)
					if(map[j] == word)
						return false;

				map[pattern[i] - 'a'] = word;
			}
			else if(map[pattern[i] - 'a'] != word)
				return false;

			start = space + 1;
		}

		return start == 0;

	}
};
// @lc code=end

