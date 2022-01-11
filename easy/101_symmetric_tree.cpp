// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
	bool rec(TreeNode* left, TreeNode* right) {
		if(!left && !right) return true;
		else if(!left || !right) return false;

		return left->val == right->val // && 
			&& rec(left->right, right->left) // && 
			&& rec(left->left, right->right);
	}

public:
	bool isSymmetric(TreeNode* root) {
		return rec(root->left, root->right);
	}
};
// @lc code=end

