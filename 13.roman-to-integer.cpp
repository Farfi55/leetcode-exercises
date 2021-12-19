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
		uint8_t romans_symbol_index['X' - 'C' + 1] = { 0 };

		romans_symbol_index['I' - 'C'] = 0; // I
		romans_symbol_index['V' - 'C'] = 1; // V
		romans_symbol_index['X' - 'C'] = 2; // X
		romans_symbol_index['L' - 'C'] = 3; // L
		romans_symbol_index['C' - 'C'] = 4; // C
		romans_symbol_index['D' - 'C'] = 5; // D
		romans_symbol_index['M' - 'C'] = 6; // M



		const uint16_t roman_values[7] = { 1, 5, 10, 50, 100, 500, 1000 };
		uint16_t sum = 0;

		for(uint8_t i = 0; i < s.size(); i++) {
			const char symbol = s[i];
			const uint8_t symbol_index = romans_symbol_index[symbol - 'C'];
			const uint16_t value = roman_values[symbol_index];

			if(i == s.size() - 1) {
				sum += value;
				break;
			}

			if(symbol_index % 2 == 0) {
				const uint8_t next_symbol_index = romans_symbol_index[s[i + 1] - 'C'];

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

