// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem279.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */


#include <vector>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
	vector<int> squares;
public:
	int numSquares(int n) {
		int n_sqrt = sqrt(n);
		for(int i = 1; i <= n_sqrt; i++) {
			squares.push_back(i * i);
		}

		

		return -1;

	}
};
// @lc code=end

