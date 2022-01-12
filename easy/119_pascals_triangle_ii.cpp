// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem119.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> nums(rowIndex + 1, 0);
		nums[0] = 1;
		for(int i = 1; i <= rowIndex; i++) {
			for(int j = i; j > 0; j--) {
				nums[j] += nums[j - 1];
			}
		}

		return nums;
	}
};
// @lc code=end

