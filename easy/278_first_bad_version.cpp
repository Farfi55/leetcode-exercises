/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

bool isBadVersion(int version);

#include <stdint.h>
using namespace std;

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		uint32_t left = 0, right = n - 1;
		while(left <= right) {
			uint32_t middle = (left + right) / 2;
			if(isBadVersion(middle)) right = middle - 1;
			else left = middle + 1;
		}
		return left;
	}
};
// @lc code=end

