/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

#include <string>

using namespace std;


// @lc code=start
class Solution {
public:
	string minRemoveToMakeValid(string s) {
		int difference = 0;

		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '(')
				++difference;
			else if(s[i] == ')') {
				if(difference == 0)
					s[i] = '*';
				else --difference;
			}
		}

		difference = 0;
		for(int i = s.length() - 1; i >= 0; --i) {
			if(s[i] == ')')
				++difference;
			else if(s[i] == '(') {
				if(difference == 0)
					s[i] = '*';
				else --difference;
			}
		}


		string out;

		for(int i = 0; i < s.length(); i++)
			if(s[i] != '*')
				out += s[i];

		return out;
	}
};
// @lc code=end

