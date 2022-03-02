#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
	int arraySign(vector<int>& nums) {
		int sign = 1;

		for(int x : nums) {
			if(x < 0) sign = -sign;
			else if(x == 0) return 0;
		}
		return sign;
	}
};
// @lc code=end

