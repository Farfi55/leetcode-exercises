/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.length(); i++) {
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] += 32;
        }
        return s;
    }
};
// @lc code=end

