/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

#include <vector>
using namespace std;

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
	void post(TreeNode* node, vector<int>& values) {
		if(!node) return;

		post(node->left, values);
		post(node->right, values);
		values.push_back(node->val);
	}
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> out;
		post(root, out);
		return out;
	}
};
// @lc code=end

