/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
int hammingWeight(int n) {
    int counter = 0;

    while(n) {
        n &= (n - 1);
        counter++;
    }
    return counter;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            auto hwa = hammingWeight(a);
            auto hwb = hammingWeight(b);
            return hwa < hwb || (hwa == hwb && a < b);
            });
        return arr;
    }
};
// @lc code=end

