/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
		int v1 = p->val;
		int v2 = q->val;


		while(node) {
			int val = node->val;

			if(v1 < val && v2 < val)
				node = node->left;
			else if(v1 > val && v2 > val)
				node = node->right;
			else return node;
		}
		return node;
	}
};
// @lc code=end

