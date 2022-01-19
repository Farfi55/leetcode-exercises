/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
	bool isSubsequence(string s, string t) {
		const int m = s.length();
		const int n = t.length();
		int i = 0, j = 0;

		while(i < m && j < n) {
			if(s[i] == t[j])
				i++;

			j++;
		}

		return i == m;
	}

	// for follow-up

	bool isSubsequence(vector<string> ss, string t) {

		vector<int> a[26] = {};

		for(int i = 0; i < t.length(); i++) {
			a[t[i] - 'a'].push_back(i);
		}

		for(string sub_s : ss) {
			for(int pre = 0; pre < sub_s.length(); pre++) {
				uint8_t c = sub_s[pre] - 'a';
				if(!binary_search(a[c].begin(), a[c].end(), pre))
					return false;
			}
		}
		return true;
	}
};
// @lc code=end

