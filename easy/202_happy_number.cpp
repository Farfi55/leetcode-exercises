/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
	int max_depth = 32;
	bool isHappy(int n) {
		int sum = 0;

		while(n) {
			sum += (n % 10) * (n % 10);
			n /= 10;
		}

		if(sum == 1) return true;
		else if(!max_depth--)return false;
		return isHappy(sum);
	}
};
// @lc code=end

