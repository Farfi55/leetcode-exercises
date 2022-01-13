// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem191.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int counter = 0;

		while(n) {
			n &= (n - 1);
			counter++;
		}
		return counter;
	}
};
// @lc code=end

