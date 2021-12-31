/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include<string>
#include<vector>

using namespace std;


// @lc code=start
class Solution {

	void solve(string& digits, int i, vector<string>& letters,
		string& current, vector<string>& combinations) {
		if(i == digits.length())
			combinations.push_back(current);
		else {
			string possible_letters = letters[digits[i] - '2'];
			for(char letter : possible_letters) {
				current += letter;
				solve(digits, i + 1, letters, current, combinations);
				current.pop_back();
			}
		}

	}
public:
	vector<string> letterCombinations(string digits) {
		int n_digits = digits.length();
		vector<string> letters{
			"abc",	// 2
			"def",	// 3
			"ghi",	// 4
			"jkl",	// 5
			"mno", 	// 6
			"pqrs",	// 7
			"tuv",	// 8
			"wxyz"	// 9
		};
		vector<string> combinations;
		string current = "";
		if(n_digits > 0)
			solve(digits, 0, letters, current, combinations);
		return combinations;
	}
};
// @lc code=end

