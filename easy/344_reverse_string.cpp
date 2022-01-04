/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
	void reverseString(vector<char>& s) {
		int i = 0;
		int j = s.size() - 1;
		while(i < j) {
			char tmp = s[i];
			s[i++] = s[j];
			s[j--] = tmp;
		}
	}
};
// @lc code=end

