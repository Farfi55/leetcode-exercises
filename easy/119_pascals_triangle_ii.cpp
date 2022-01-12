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
		vector<int> nums(rowIndex + 1, 1);

		for(int i = 0; i <= rowIndex; i++) {
			int prev = 1;
			for(int j = 1; j < i; j++) {
				nums[j] += prev;
				prev = nums[j] - prev;
			}
		}

		return nums;
	}
};
// @lc code=end

