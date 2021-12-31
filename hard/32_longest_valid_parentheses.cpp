/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

	// @lc code=start
class Solution {
	int validLenght(string s, int i) {
		int n = s.length();
		int diff = 0;
		int start = i;
		int max_valid = 0;
		while(i < n) {
			if(s[i] == '(') {
				diff++;
				i++;
				if(diff > n - i)
					break;
			}
			else { // s[i] == ')'
				diff--;
				i++;
				// for sure valid untill here
				if(diff == 0) {
					if(i - start > max_valid)
						max_valid = i - start;
				}
				else if(diff < 0) {
					break;
				}
			}

		}
		return max_valid;
	}
public:
	int longestValidParentheses(string s) {
		int n = s.length();
		int max_valid = 0;
		for(int i = 0; i < n; i++) {
			int curr_valid = validLenght(s, i);
			if(curr_valid > max_valid)
				max_valid = curr_valid;
		}
		return max_valid;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	cout << sol.longestValidParentheses(")()(()))");
	return 0;
}
