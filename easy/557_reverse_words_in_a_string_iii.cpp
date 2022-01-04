/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
	void reverseString(string& s, int left, int right) {
		while(left < right) {
			char tmp = s[left];
			s[left++] = s[right];
			s[right--] = tmp;
		}
	}

public:
	string reverseWords(string s) {
		const int n = s.length();

		size_t start = 0;
		size_t end = 0;
		while(start < n) {
			end = s.find(" ", start) - 1;
			if(end >= n) end = n - 1;
			reverseString(s, start, end);
			start = end + 2;
		}
		return s;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	string s = "Let's take LeetCode contest";
	cout << Solution().reverseWords(s);
	return 0;
}
