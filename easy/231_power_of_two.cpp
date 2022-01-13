/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */


// 7: 0000 0111
// 8: 0000 1000
// 9: 0000 1001

// 7: 		0000 0111
// 8: 		0000 1000
// 8 & 7: 	0000 0000

// 9 & 8: 	0000 1000

// when we AND the bits of a power of 2 
// with itself -1 we get a 'all 0' bitstring
// we can use this to check if a number is a power of 2

// @lc code=start
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if(n <= 0) return false;
		return (n & (n - 1) == 0);
	}
};
// @lc code=end

