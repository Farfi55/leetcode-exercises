// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem763.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


// @lc code=start
class Solution {
public:
	vector<int> partitionLabels(string s) {
		int n = s.size();
		vector<int> out;

		// int last[26];
		// for(int i = 0; i < n; i++) {
		// 	last[s[i] - 'a'] = i;
		// }


		int start = 0;
		while(start < n) {
			int size = 1;
			for(int i = start; i < start + size; i++) {

				for(int j = n - 1; j > i; j--) {
					if(s[j] == s[i]) {
						size = max(size, j - start + 1);
						break;
					}
				}
			}
			out.push_back(size);
			start += size;
		}

		return out;
	}
};
// @lc code=end

