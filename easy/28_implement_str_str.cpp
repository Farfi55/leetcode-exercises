/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	int strStr(string haystack, string needle) {
		const int n = haystack.size();
		const int m = needle.size();

		for(int i = 0; i <= n - m; i++) {
			bool found = true;
			for(int j = 0; found && j < m; j++) {
				if(needle[j] != haystack[i + j])
					found = false;
			}
			if(found) return i;
		}
		return -1;
	}
};
// @lc code=end

