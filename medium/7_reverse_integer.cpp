/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <climits>
#include <cmath>

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // 2^31: 2.147.483.648
        // reverse is
        // 

        if(x / 1000000000 != 0)
            if((x % 1000000000) > 463847412 ||
                (x % 1000000000) < -463847412)
                return 0;

        if(x == INT_MIN || x == INT_MAX) return 0;

        bool negative = (x < 0);
        if(negative) x = -x;


        int rev = 0;
        for(int i = 10; i > 0 && x > 0; i--) {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }

        if(negative) return -rev;
        else return rev;

    }
};
// @lc code=end

