// @before-stub-for-debug-begin
#include <vector>
#include <algorithm>
#include <string>
// #include "commoncppproblem98.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

/*
	10
  5    14
 4 6  11 17

10 [-inf, inf]

5  [-inf, 9] L
4  [-inf, 5] LL
6  [6, 9]	 LR

14 [11, inf] R
11 [11, 14]	 RL
17 [15, inf] RR
*/

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
	bool dfs(TreeNode* node, int64_t lim_left, int64_t lim_right) {
		if(!node) return true;

		if(!(lim_left <= node->val && node->val <= lim_right))
			return false;

		return dfs(node->left, lim_left, min((int64_t)node->val, lim_right) - 1) // &&
			&& dfs(node->right, max((int64_t)node->val, lim_left) + 1, lim_right);
	}
public:
	bool isValidBST(TreeNode* node) {

		return dfs(node, INT32_MIN, INT32_MAX);
	}
};
// @lc code=end

