/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

#include <vector>
#include <string>

using namespace std;


// @lc code=start
class Solution {
public:
	vector<int> partitionLabels(string s) {
		int n = s.size();
		vector<int> out;

		int last[26];
		for(int i = 0; i < n; i++)
			last[s[i] - 'a'] = i;



		int start = 0;
		while(start < n) {
			int size = 1;
			for(int i = start; i < start + size; i++) {
				size = max(size, last[s[i] - 'a'] - start + 1);
			}
			out.push_back(size);
			start += size;
		}

		return out;
	}
};
// @lc code=end

