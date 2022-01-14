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
	bool dfs(TreeNode* node, int* lim_left, int* lim_right) {
		if(!node) return true;

		if((lim_left && *lim_left >= node->val) // || 
			|| (lim_right && node->val >= *lim_right))
			return false;

		return dfs(node->left, lim_left, &node->val) // &&
			&& dfs(node->right, &node->val, lim_right);
	}
public:
	bool isValidBST(TreeNode* node) {

		return dfs(node, nullptr, nullptr);
	}
};
// @lc code=end

