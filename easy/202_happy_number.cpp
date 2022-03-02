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
			// sum the square of the last digit 
			ans += (n % 10) * (n % 10);
			n /= 10;
		}
		return ans;
	}
public:
	bool isHappy(int x) {
		// since n is at most 2^31 = 2.147.483.648 
		// to_happy can at most be to_happy(1.999.999.999)
		// wich is 1^2 + 9*(9^2) = 730
		// so we can keep track of all 
		bool arr[1000] = { false };

		x = to_happy(x);

		while(!arr[x]) { // while there is no cycles
			arr[x] = true; // store the new occurrance of x

			if(x == 1)
				return true;

			x = to_happy(x); // get next happy number
		}
		return false;
	}
};
// @lc code=end

