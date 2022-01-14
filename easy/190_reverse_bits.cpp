// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem190.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {

		uint32_t i = 0;
		uint32_t j = 31;

		while(i < j) {
			uint32_t high_val = (n & (1 << j));
			uint32_t low_val = (n & (1 << i));
			n ^= (low_val | high_val);
			n |= low_val << (j - i);
			n |= high_val >> (j - i);

			i++;
			j--;
		}

		return n;
	}
};
// @lc code=end

