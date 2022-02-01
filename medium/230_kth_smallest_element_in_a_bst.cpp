/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;

		while(root != nullptr) {
			st.push(root);
			root = root.left;
		}

		while(k != 0) {
			TreeNode node = st.top(); st.pop();
			k--;
			if(k == 0)
				return node.val;


			TreeNode* right = node->right;

			while(right != null) {
				st.push(right);
				right = right.left;
			}
		}

		return -1;
	}
};
// @lc code=end

