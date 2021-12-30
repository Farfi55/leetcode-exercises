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

		out += string((num / 1000), 'M');
		num %= 1000;
		if(num >= 900) {
			num -= 900;
			out += "CM";
		}
		else if(num >= 500) {
			num -= 500;
			out += "D";
		}
		else if(num >= 400) {
			num -= 400;
			out += "CD";
		}

		out += string((num / 100), 'C');
		num %= 100;

		if(num >= 90) {
			num -= 90;
			out += "XC";
		}
		else if(num >= 50) {
			num -= 50;
			out += "L";
		}
		else if(num >= 40) {
			num -= 40;
			out += "XL";
		}

		out += string((num / 10), 'X');
		num %= 10;

		if(num == 9) {
			num -= 9;
			out += "IX";
		}
		else if(num >= 5) {
			num -= 5;
			out += "V";
		}
		else if(num == 4) {
			num -= 4;
			out += "IV";
		}

		out += string(num, 'I');

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
