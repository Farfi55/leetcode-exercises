/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& a) {
		const int n = a.size();
		int total = 0, count = 0;

		for(int i = 2; i < n; ++i) {
			if(a[i] - a[i - 1] == a[i - 1] - a[i - 2])
				total += ++count;
			else count = 0;
		}

		return total;
	}
};
// @lc code=end

