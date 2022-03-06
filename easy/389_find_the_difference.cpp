/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int letters[26] = { };
        int n = s.length();

        for(int i = 0; i < n; i++) {
            letters[s[i] - 'a']--;
            letters[t[i] - 'a']++;
        }
        letters[t[n] - 'a']++;

        for(int i = 0; i < 26; i++) {
            if(letters[i])
                return i + 'a';
        }
        return 0;
    }
};
// @lc code=end

