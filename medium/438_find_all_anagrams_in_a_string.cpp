// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int n = s.length();
		int m = p.length();

		if(n < m) return {};

		vector<int> result;
		int s_letters[26] = { 0 };
		int p_letters[26] = { 0 };

		for(int i = 0; i < m - 1; i++) {
			s_letters[s[i] - 'a']++;
			p_letters[p[i] - 'a']++;
		}
		p_letters[p[m - 1] - 'a']++;

		for(int i = 0; i <= n - m; i++) {
			s_letters[s[i + m - 1] - 'a']++;

			bool is_anagram = true;

			for(int j = 0; j < 26 && is_anagram; j++)
				if(s_letters[j] != p_letters[j])
					is_anagram = false;


			if(is_anagram)
				result.push_back(i);

			s_letters[s[i] - 'a']--;
		}

		return result;
	}
};
// @lc code=end

