/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:

	bool isMatch(string s, string p) {
		vector<vector<int>> data = vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, -1));
		return isMatch(s, p, 0, 0, data);
	}

	bool isMatch(const string& str, const string& patt, int idx_s, int idx_p, vector<vector<int>>& data) {

		if(data[idx_s][idx_p] != -1) return data[idx_s][idx_p];

		bool ans = false;
		if(idx_p == patt.length())
			ans = (idx_s == str.length());
		else if(idx_p < patt.length() - 1 && patt[idx_p + 1] == '*') {
			// case 0 repetitions:
			if(isMatch(str, patt, idx_s, idx_p + 2, data)) ans = true;
			else {
				// while the char we are repeating matches
				// the string we can try using it to "cover" that next character
				while(idx_s < str.length() &&
					(patt[idx_p] == '.' || str[idx_s] == patt[idx_p])) {
					idx_s++;
					if(isMatch(str, patt, idx_s, idx_p + 2, data)) {
						ans = true;
						break;
					}
				}
			}
		}
		else {
			ans = (idx_s < str.length()
				&& (patt[idx_p] == '.' || str[idx_s] == patt[idx_p])
				&& isMatch(str, patt, idx_s + 1, idx_p + 1, data));
		}

		data[idx_s][idx_p] = ans;
		return ans;

	}
};
// @lc code=end


int main(int argc, char const* argv[])
{
	Solution sol;
	cout << sol.isMatch("a", ".*..a*");
	return 0;
}
