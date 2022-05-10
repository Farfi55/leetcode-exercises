/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        if(m > n)
            return addBinary(b, a);

        uint8_t carry = 0;
        int i;
        for(i = 0; i < m; i++) {
            char digit = a[n - 1 - i] + b[m - 1 - i] + carry - '0' - '0';
            carry = digit / 2;
            digit %= 2;
            a[n - 1 - i] = digit + '0';
        }

        for(;carry && i < n; i++) {
            a[n - 1 - i] += carry;
            carry = a[n - 1 - i] >= '2';
            a[n - 1 - i] -= carry * 2;
        }

        if(carry)
            a = '1' + a;

        return a;
    }
};
// @lc code=end

