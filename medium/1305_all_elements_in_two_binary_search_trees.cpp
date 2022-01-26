/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 */

#include <vector>
#include <algorithm>

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
	void dfs(TreeNode* node, vector<int>& nums) {
		if(!node) return;

		dfs(node->left, nums);
		nums.push_back(node->val);
		dfs(node->right, nums);
	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> out;
		dfs(root1, out);
		dfs(root2, out);
		sort(out.begin(), out.end());
		return out;
	}
};
// @lc code=end

