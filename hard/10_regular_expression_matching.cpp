/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	//"abbba"
	//"b*ab*.." true

	/*
	for english letters you match them against the string
	for . you just make sure the string is not over
	for * you iterate like this:
		try 0 times
		try 1..n times where n is the number of the caracter in the string
		right after the *
		example:
		s: asddddda
		p: asdd*a

		when we get to *
		the string will be
		s: dddda
		p: d*a
		so we try 1..4 (inclusive) repetitions, if none of them return a valid string
		then we will never find one

	for .*
	*/


	bool isMatch(string s, string p) {
		return isMatch(s, p, 0, 0);
	}

	bool charMatch(char str_char, char pattern_char) {
		return pattern_char == '.' || str_char == pattern_char;
	}

	bool canIgnoreRemainingPattern(string& p, int idx_p) {
		//if the remaining pattern has an odd number of characters we can't ignore it 
		if((p.length() - idx_p) % 2) return false;

		for(; idx_p < p.length(); idx_p += 2) {
			if(p[idx_p + 1] != '*') return false;
		}
		return true;
	}


/*
	"aa"
	"a*"
*/
	bool isMatch(string& s, string& p, int idx_s, int idx_p) {
		// if we're done with the string and the pattern we
		if(s.length() == idx_s)
			return (p.length() == idx_p
				|| canIgnoreRemainingPattern(p, idx_p));
		if(p.length() == idx_p) return false;

		if(idx_p < p.length() - 1 && p[idx_p + 1] == '*') {
			// case 0 repetitions:
			// we ignore the "_*"
			if(isMatch(s, p, idx_s, idx_p + 2)) return true;

			// while the char we are repeating matches
			// the string we can try using it to "cover" that next character
			while(idx_s < s.length() && charMatch(s[idx_s], p[idx_p])) {
				idx_s++;
				if(isMatch(s, p, idx_s, idx_p + 2)) return true;
			}
			// if no combination worked then this doesn't match
			return false;
		}
		else
			return charMatch(s[idx_s], p[idx_p])
			&& isMatch(s, p, idx_s + 1, idx_p + 1);

	}
};
// @lc code=end


int main(int argc, char const* argv[])
{
	Solution sol;
	cout << sol.isMatch("a", "ab*");
	return 0;
}
