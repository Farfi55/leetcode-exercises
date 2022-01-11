// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem264.h"
#include <set>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
	int nthUglyNumber(const int n) {

		vector<int> ugly(n, 1);
		int l2 = 0, l3 = 0, l5 = 0;

		for(int i = 1; i < n; i++) {
			ugly[i] = min(ugly[l2] * 2, min(ugly[l3] * 3, ugly[l5] * 5));
			if(ugly[i] == ugly[l2] * 2) l2++;
			if(ugly[i] == ugly[l3] * 3) l3++;
			if(ugly[i] == ugly[l5] * 5) l5++;
		}
		return ugly[n - 1];

	}
};
// @lc code=end

