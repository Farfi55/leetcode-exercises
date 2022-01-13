// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
	int to_happy(int n) {
		int ans = 0;
		while(n) {
			ans += (n % 10) * (n % 10);
			n /= 10;
		}
		return ans;
	}
public:
	int max_depth = 32;
	bool isHappy(int x) {
		bool arr[1000] = { false };
		x = to_happy(x);
		while(!arr[x]) {
			arr[x] = true;
			if(x == 1)
				return true;
			x = to_happy(x);
		}
		return false;
	}
};
// @lc code=end

