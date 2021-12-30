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
	vector<vector<int8_t>> data;


	bool isMatch(string s, string p) {

		data = vector<vector<int8_t>>(s.length() + 1, vector<int8_t>(p.length() + 1, -1));
		return isMatch(s, p, 0, 0);
	}

	bool charMatch(char str_char, char pattern_char) {
		return pattern_char == '.' || str_char == pattern_char;
	}

	// bool canIgnoreRemainingPattern(string& p, int idx_p) {
	// 	//if the remaining pattern has an odd number of characters we can't ignore it 
	// 	if((p.length() - idx_p) % 2) return false;

	// 	for(; idx_p < p.length(); idx_p += 2) {
	// 		if(p[idx_p + 1] != '*') return false;
	// 	}
	// 	return true;
	// }


/*
	"aa"
	"a*"
*/
	bool isMatch(string& str, string& patt, int idx_s, int idx_p) {

		if(data[idx_s][idx_p] != -1) return  data[idx_s][idx_p];

		bool ans = false;
		// if we're done with the string and the pattern we
		// if(str.length() == idx_s)
		// 	return (patt.length() == idx_p
		// 		|| canIgnoreRemainingPattern(patt, idx_p));
		if(idx_p == patt.length())
			ans = (idx_s == str.length());
		else if(idx_p < patt.length() - 1 && patt[idx_p + 1] == '*') {
			// case 0 repetitions:
			// we ignore the "_*"
			if(isMatch(str, patt, idx_s, idx_p + 2)) ans = true;
			else {
				// while the char we are repeating matches
				// the string we can try using it to "cover" that next character
				while(idx_s < str.length() && charMatch(str[idx_s], patt[idx_p])) {
					idx_s++;
					if(isMatch(str, patt, idx_s, idx_p + 2)) {
						ans = true;
						break;
					}
				}
			}
			// if no combination worked then this doesn't match
			// ans = false;
		}
		else
			ans = (idx_s < str.length() && charMatch(str[idx_s], patt[idx_p])
				&& isMatch(str, patt, idx_s + 1, idx_p + 1));

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
