// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem383.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int n = ransomNote.length();
		int m = magazine.length();

		if(n > m) return false;

		int ransom_letters[26] = { 0 };
		int magazine_letters[26] = { 0 };

		for(char& c : ransomNote)
			ransom_letters[c - 'a']++;

		for(char& c : magazine)
			magazine_letters[c - 'a']++;


		for(int i = 0; i < 26; i++)
			if(magazine_letters[i] < ransom_letters[i])
				return false;

		return true;


	}
};
// @lc code=end

