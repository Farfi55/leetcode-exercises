/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int n = words.size();
		vector<string> out;
		int start = 0;
		int end = 0;
		while(end != n) {
			end = start;
			int capacity = maxWidth - words[end++].length();
			while(end < n && capacity > words[end].length()) {
				capacity -= words[end++].length() + 1;
			}
			bool last_line = (end == n);

			int separations = end - start - 1;
			int spaces = 1;
			if(!last_line && separations > 0) {
				spaces += capacity / separations;
				capacity %= separations;
			}


			string line = words[start];
			for(int i = start + 1; i < end; i++) {
				if(last_line) line += ' ';
				else line += string(spaces + (capacity-- > 0), ' ');
				line += words[i];
			}
			if(last_line || separations == 0) line += string(capacity, ' ');
			out.push_back(line);

			start = end;
		}
		return out;
	}
};
// @lc code=end


int main(int argc, char const* argv[])
{
	Solution sol;
	vector<string> words;

	string line; cin >> line;
	while(line != "-1") {
		words.push_back(line);
		cin >> line;
	}
	int max_width; cin >> max_width;

	auto out = sol.fullJustify(words, max_width);

	for(string& out_line : out) {
		cout << out_line << endl;
	}
	return 0;
}

