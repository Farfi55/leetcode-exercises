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
		std::map<char, int> romans_symbol_value = {
			{'I',1},
			{'V',5},
			{'X',10},
			{'L',50},
			{'C',100},
			{'D',500},
			{'M',1000}
		};

		int sum = 0;


		for(int i = 0; i < s.size(); i++) {
			char symbol = s[i];

			if(i == s.size() - 1) {
				sum += romans_symbol_value[symbol];
				break;
			}

			if(symbol == 'I') {
				if(s[i + 1] == 'V') {
					sum += 4;
					i++;
					continue;
				}
				else if(s[i + 1] == 'X') {
					sum += 9;
					i++;
					continue;
				}
			}
			else if(symbol == 'X') {
				if(s[i + 1] == 'L') {
					sum += 40;
					i++;
					continue;
				}
				else if(s[i + 1] == 'C') {
					sum += 90;
					i++;
					continue;
				}
			}
			else if(symbol == 'C') {
				if(s[i + 1] == 'D') {
					sum += 400;
					i++;
					continue;
				}
				else if(s[i + 1] == 'M') {
					sum += 900;
					i++;
					continue;
				}
			}
			sum += romans_symbol_value[symbol];

		}

		return sum;
	}

};
// @lc code=end

