/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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

	void dfs(TreeNode* node, int targetSum, vector<int>& curr, vector<vector<int>>& solutions) {
		if(!node)
			return;

		targetSum -= node->val;
		curr.push_back(node->val);

		if(!node->left && !node->right) {
			if(targetSum == 0)
				solutions.push_back(curr);
		}
		else {
			if(node->left)
				dfs(node->left, targetSum, curr, solutions);
			if(node->right)
				dfs(node->right, targetSum, curr, solutions);
		}

		curr.pop_back();
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> solutions;
		vector<int> curr;
		dfs(root, targetSum, curr, solutions);
		return solutions;

	}
};
// @lc code=end

