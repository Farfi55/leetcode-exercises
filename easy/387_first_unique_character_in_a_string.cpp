// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem387.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
	int firstUniqChar(string s) {
		unsigned n = s.length();
		unsigned chars[26] = { 0 };
		unsigned first_pos[26] = { 0 };

		for(unsigned i = 0; i < n; i++) {
			if(!chars[s[i] - 'a']++) {
				first_pos[s[i] - 'a'] = i;
			}
		}

		unsigned pos = -1;
		for(unsigned i = 0; i < 26; i++) {
			if(chars[i] == 1)
				pos = min(pos, first_pos[i]);
		}
		return int(pos);


	}
};
// @lc code=end

