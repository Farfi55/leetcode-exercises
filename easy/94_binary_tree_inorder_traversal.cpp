/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
	void inorder(TreeNode* node, vector<int>& values) {
		if(!node) return;

		inorder(node->left, values);
		values.push_back(node->val);
		inorder(node->right, values);
	}

public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> out;
		inorder(root, out);
		return out;
	}
};
// @lc code=end

