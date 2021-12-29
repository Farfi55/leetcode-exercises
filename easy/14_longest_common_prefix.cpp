/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

	string longestCommonPrefix(vector<string>& strs) {
		const int n = strs.size();

		int min_size = strs[0].size();
		for(int i = 1; i < n; i++)
			if(strs[i].size() < min_size)
				min_size = strs[i].size();



		for(int letter_idx = 0; letter_idx < min_size; letter_idx++) {
			for(int i = 1; i < n; i++) {
				if(strs[0][letter_idx] != strs[i][letter_idx]) {
					return strs[0].substr(0, letter_idx);
				}
			}
		}
		return strs[0].substr(0, min_size);
	}


};
// @lc code=end

