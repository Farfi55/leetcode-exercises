/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int n = nums.size();
		for(int i = 0; i < n;) {
			int val = nums[i];
			int square = val * val;
			nums[i++] = square;
			while(i < n && nums[i] == val)
				nums[i++] = square;
		}
		sort(nums.begin(), nums.end());
		return nums;
	}
};
// @lc code=end

