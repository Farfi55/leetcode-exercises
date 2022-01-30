/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if(!root) return nullptr;


		if(key < root->val)
			root->left = deleteNode(root->left, key);
		else if(key > root->val)
			root->right = deleteNode(root->right, key);
		else { // key == root->val
			// no children
			if(!root->left && !root->right)
				return nullptr;

			// only one children -> replace node with children
			if(!root->left || !root->right)
				return root->left ? root->left : root->right;


			// two children -> replace node with lowest node higher than key
			TreeNode* min_node = root->right;
			while(min_node->left)
				min_node = min_node->left;

			root->val = min_node->val;	// swap node's value
			root->right = deleteNode(root->right, min_node->val); // delete swapped node
		}

		return root;
	}
};
// @lc code=end

