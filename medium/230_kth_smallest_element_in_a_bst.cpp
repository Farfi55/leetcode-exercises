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
	vector<int> nums;

	void dfs(TreeNode* node) {
		if(!node) return;

		nums.push_back(node->val);
		dfs(node->left);
		dfs(node->right);
	}

public:
	int kthSmallest(TreeNode* root, int k) {
		dfs(root);

		sort(nums.begin(), nums.end());
		return nums[k - 1];
	}
};
// @lc code=end

