/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
	// void recurvive(vector<int>& out, int num, const int& low, const int& high) {

	// 	if(num > high) return;

	// 	if(num >= low)
	// 		out.push_back(num);

	// 	int last_digit = num % 10;
	// 	if(last_digit != 9)

	// }


public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> out;
		string sequence = "123456789";

		for(int size = 2; size < 10; size++) {
			for(int i = 0; i < 10 - size; i++) {
				int num = stoi(sequence.substr(i, size));
				if(num > high)
					return out;


				if(num >= low)
					out.push_back(num);
			}
		}

		return out;

	}
};
// @lc code=end

