// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
// #include "commoncppproblem96.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// 1 : 1
// 2 : 2
// 3 : 5
// 4 : 14
// 5 : 42
// 6 : 132



// @lc code=start
class Solution {
	int dfs(int depth, int n) {
		if(depth == n) return 1;
		return 2 * dfs(depth + 1, n);
	}

public:
	int numTrees(int n) {
		return dfs(0, n);
	}
};
// @lc code=end

