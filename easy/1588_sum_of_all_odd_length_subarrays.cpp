/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

// @lc code=start
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i = 1; i <= n; i += 2)
            for(int j = 0; j <= n - i; j++)
                for(int k = 0; k < i; k++)
                    sum += arr[j + k];
        return sum;
    }
};
// @lc code=end

