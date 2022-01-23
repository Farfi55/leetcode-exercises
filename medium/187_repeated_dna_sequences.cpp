/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		const int n = s.length();
		if(n <= 10) return {};


		int to_int[20] = { 0 };
		to_int['A' - 'A'] = 0; // A
		to_int['C' - 'A'] = 1; // C
		to_int['G' - 'A'] = 2; // G
		to_int['T' - 'A'] = 3; // T

		vector<string> out;
		unordered_map<uint32_t, int> sequences;

		uint32_t sequence = 0;
		for(int i = 0; i < 10; i++) {
			sequence = sequence * 10 + (to_int[s[i] - 'A']);
		}

		sequences[sequence] = 1;

		for(int i = 10; i < n; i++) {
			sequence = (sequence % 1000000000U) * 10 + (to_int[s[i] - 'A']);

			if(sequences[sequence]++ == 1)
				out.push_back(s.substr(i - 9, 10));
		}

		return out;
	}
};
// @lc code=end

