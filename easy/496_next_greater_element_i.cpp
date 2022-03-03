
#include <vector>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_map;

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

        unordered_map<int, int> map;
        std::stack<int> stack;


        for(int x : nums2) {
            while(!stack.empty() && stack.top() < x) {
                map[stack.top()] = x;
                stack.pop();
            }
            stack.push(x);
        }

        for(int i = 0; i < n; i++) {
            nums1[i] = map[nums1[i]] == 0 ? -1 : map[nums1[i]];
        }

        return nums1;
    }
};
// @lc code=end

