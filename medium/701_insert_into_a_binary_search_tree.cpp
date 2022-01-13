/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if(!root) return new TreeNode(val);

		TreeNode* curr = root;
		TreeNode* new_node = new TreeNode(val);

		while(true) {
			if(val < curr->val) {
				if(curr->left)
					curr = curr->left;
				else {
					curr->left = new_node;
					break;
				}
			}
			else {
				if(curr->right)
					curr = curr->right;
				else {
					curr->right = new_node;
					break;
				}
			}
		}
		return root;
	}
};
// @lc code=end

