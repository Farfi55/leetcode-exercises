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

        for(int i = 0; i < n; i++) {
            if(s[i] == '1' || s[i] == '2') {
                if(i >= n - 1 || s[i + 2] != '#')
                    out += s[i] + 48;
                else {
                    out += s[i + 1] + 48 + (s[i] - '0') * 10;
                    i += 2;
                }
            }
            else
                out += s[i] + 48;
        }
        return out;

    }
};
// @lc code=end

