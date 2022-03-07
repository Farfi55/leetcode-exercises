/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
public:
    string freqAlphabets(string s) {
        string out = "";

        int n = s.length();

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '#') {
                char c = (s[i - 2] - '0') * 10 + s[i - 1] + 48;
                out = c + out;
                i -= 2;
            }
            else {
                char c = s[i] + 48;
                out = c + out;
            }
        }
        return out;
    }
};
// @lc code=end

