/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {

	// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
	void kmp(string patt, vector<int>& lps) {
		int m = patt.size();
		int len = 0;
		int i = 1;

		lps[0] = 0;
		while(i < m) {
			if(patt[i] == patt[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else { // (patt[i] != patt[len])
				if(len != 0) {
					len = lps[len - 1];
				}
				else { // (len == 0)
					lps[i] = 0;
					i++;
				}
			}
		}
	}

public:
	int strStr(string haystack, string needle) {
		const int n = haystack.size();
		const int m = needle.size();

		if(m == 0) return 0;

		vector<int> lps(m, 0);

		kmp(needle, lps);

		int i = 0, j = 0;

		while(i < n) {
			if(needle[j] == haystack[i]) {
				j++;
				i++;
			}
			if(j == m) {
				return i - j;
				// if all matches were needed
				j = lps[j - i];
			}
			else if(i < n && needle[j] != haystack[i]) {
				if(j != 0)
					j = lps[j - 1];
				else i++;
			}
		}
		return -1;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	cout << sol.strStr("ABABDABACDABABCABAB", "ABABCABAB");
	return 0;
}
