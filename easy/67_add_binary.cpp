/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string out = "";
        int n = a.length() - 1;
        int m = b.length() - 1;
        int max_len = max(n, m);
        char carry = 0;

        for(int i = 0; carry > 0 || i <= max_len; i++) {
            char v1 = 0, v2 = 0;
            if(i <= n)
                v1 = a[n - i] - '0';
            if(i <= m)
                v2 = b[m - i] - '0';
            char vout = v1 + v2 + carry;
            carry = vout / 2;
            vout %= 2;
            out = (char)(vout + '0') + out;
        }
        return out;
    }
};
// @lc code=end

