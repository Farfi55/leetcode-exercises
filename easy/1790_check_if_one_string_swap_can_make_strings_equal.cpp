#include <string>

using namespace std;

/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

// @lc code=start
class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		const int n = s1.length();

		bool hasSwapped = false;

		for(int i = 0; i < n; i++) {
			if(s1[i] != s2[i]) {
				if(hasSwapped)
					return false; // we can only swap once!

				// search for a character to swap
				// we ignore the character if it is 
				for(int j = i + 1; j < n; j++) {
					if(s1[i] == s2[j] && s1[j] != s2[j]) {
						swap(s2[i], s2[j]);
						hasSwapped = true;
					}
				}
				// if we haven't found anything to swap with then it can't be made equal
				if(!hasSwapped)
					return false;
			}
		}

		return true;
	}
};
// @lc code=end

