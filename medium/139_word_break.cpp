// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

// @lc code=start
class Solution {
	unordered_set<string> dict;
	set<int> sizes;

	bool rec(string& s, int start) {
		if(start == s.length()) return true;

		for(const int& len : sizes) {
			if(start + len > s.length()) return false;
			else if(dict.find(s.substr(start, len)) != dict.end()) // &&
				if(rec(s, start + len) == true)
					return true;
		}
		return false;
	}


public:
	bool wordBreak(string s, vector<string>& wordDict) {
		for(string& word : wordDict) {
			sizes.insert(word.length());
			dict.insert(word);
		}
		return rec(s, 0);
	}
};
// @lc code=end

// int main(int argc, char const* argv[])
// {
// 	vector<string> a{ "leet", "code" };
// 	cout << Solution().wordBreak("leetcode", a);
// 	return 0;
// }
