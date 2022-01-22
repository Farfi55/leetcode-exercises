/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int letters[26] = { 0 };
		vector<bool> used(strs.size(), false);

		vector<vector<string>> out;

		for(int i = 0; i < strs.size(); i++) {
			if(used[i])
				continue;

			string& str_base = strs[i];
			out.push_back({ str_base });
			used[i] = true;

			for(int j = 0; j < str_base.length(); j++) {
				letters[str_base[j] - 'a']++;
			}


			for(int k = 0; k < strs.size(); k++) {
				if(used[k])
					continue;
				string& str_current = strs[k];
				for(int l = 0; l < str_current.length(); l++)
					letters[str_current[l] - 'a']--;


				bool all_zero = true;

				for(int m = 0; m < 26 && all_zero; m++)
					if(letters[m] != 0)
						all_zero = false;


				if(all_zero) {
					out.back().push_back(str_current);
					used[k] = true;
				}


				for(int l = 0; l < str_current.length(); l++)
					letters[str_current[l] - 'a']++;

			}




			for(int j = 0; j < str_base.length(); j++) {
				letters[str_base[j] - 'a']--;
			}

		}

		return out;

	}
};
// @lc code=end

