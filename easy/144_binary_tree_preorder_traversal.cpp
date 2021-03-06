/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
	void pre(TreeNode* node, vector<int>& values) {
		if(!node) return;

		values.push_back(node->val);
		pre(node->left, values);
		pre(node->right, values);
	}
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> out;
		pre(root, out);
		return out;
	}
};
// @lc code=end

