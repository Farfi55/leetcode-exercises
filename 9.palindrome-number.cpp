/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        string num = to_string(x);
        int n = num.length();
        for(int i = 0; i < n / 2; i++)
            if(num[i] != num[n - i - 1])
                return false;
        return true;
        // int sum = 0;
        // while(x > sum) {
        //     sum = (sum * 10) + (x % 10);
        //     x = x / 10;
        // }

        // return (x == sum) || (x == sum / 10);

    }
};
// @lc code=end

