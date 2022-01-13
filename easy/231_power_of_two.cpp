/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if(n <= 0) return false;

		int counter = 0;
		for(int i = 0; i < 32; i++) {
			counter += (n & 1);
			n >>= 1;
		}
		return counter == 1;
	}
};
// @lc code=end

