/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */


#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
	int romanToInt(string s) {
		std::map<char, int> romans_symbol_index = {
			{'I',0},
			{'V',1},
			{'X',2},
			{'L',3},
			{'C',4},
			{'D',5},
			{'M',6}
		};



		int roman_values[7] = { 1, 5, 10, 50, 100, 500, 1000 };


		int sum = 0;


		for(int i = 0; i < s.size(); i++) {
			const char symbol = s[i];
			const int symbol_index = romans_symbol_index[symbol];
			const int value = roman_values[symbol_index];

			if(i == s.size() - 1) {
				sum += value;
				break;
			}

			if(symbol_index % 2 == 0) {
				const int next_symbol_index = romans_symbol_index[s[i + 1]];

				if(next_symbol_index - symbol_index == 2 ||
					next_symbol_index - symbol_index == 1) {
					sum += roman_values[next_symbol_index] - value;
					i++;
				}
				else sum += value;
			}
			else sum += value;
		}

		return sum;
	}

};
// @lc code=end

