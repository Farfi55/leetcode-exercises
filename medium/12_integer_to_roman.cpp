/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
	string intToRoman(int num) {
		string out = "";
		const uint16_t roman_values[7] = { 1000, 500, 100, 50, 10, 5, 1 };
		const char roman_symbols[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };


		for(int i = 0; i < 7; i += 2) {
			int val = roman_values[i];
			int times = num / val;
			if(times == 9) {
				out += roman_symbols[i];
				out += roman_symbols[i - 2];
			}
			else if(times == 4) {
				out += roman_symbols[i];
				out += roman_symbols[i - 1];
			}
			else {
				if(times >= 5) {
					out += roman_symbols[i - 1];
					times -= 5;
				}
				out += string(times, roman_symbols[i]);
			}
			num %= val;
		}

		return out;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	int x; cin >> x;
	cout << Solution().intToRoman(x) << endl;

	return 0;
}
