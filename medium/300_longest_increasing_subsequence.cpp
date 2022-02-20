// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem300.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


// @lc code=start
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> sub;
		for(int x : nums) {
			if(sub.empty() || sub[sub.size() - 1] < x) {
				sub.push_back(x);
			}
			else {
				auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
				*it = x; // Replace that number with x
			}
		}
		return sub.size();
	}
};
// @lc code=end

