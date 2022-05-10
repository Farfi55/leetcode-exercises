/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n]++;
        while(digits[n] >= 10) {
            digits[n] = 0;
            if(n > 0)
                digits[--n]++;
            else
                digits.insert(digits.begin(), 1);

        }
        return digits;
    }
};
// @lc code=end

