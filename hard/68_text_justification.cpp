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
	string format_last_line(vector<string>& words, int maxWidth, int start, int end, int capacity) {
		string line = words[start];
		for(int i = start + 1; i < end; i++) {
			line += ' ';
			line += words[i];
		}
		line += string(capacity, ' ');
		return line;
	}

	string format_line(vector<string>& words, int maxWidth, int start, int end, int capacity) {
		if(end == words.size())
			return format_last_line(words, maxWidth, start, end, capacity);

		string line = words[start];
		int spaces = 1;
		int separations = end - start - 1;
		if(separations > 0) {
			spaces += capacity / separations;
			capacity %= separations;
		}

		for(int i = start + 1; i < end; i++) {
			line += string(spaces + (capacity-- > 0), ' ');
			line += words[i];
		}

		if(separations == 0) line += string(capacity, ' ');
		return line;
	}


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

			out.push_back(format_line(words, maxWidth, start, end, capacity));
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

