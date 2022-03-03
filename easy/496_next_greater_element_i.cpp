/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        const int m = nums2.size();

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j]) {
                    for(; j < m; j++)
                        if(nums2[j] > nums1[i]) {
                            ans[i] = nums2[j];
                            break;
                        }
                    break;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

