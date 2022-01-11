// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem102.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	void dfs(TreeNode* node, int depth, vector<vector<int>>& out) {
		if(!node) return;

		if(depth >= out.size()) out.push_back(vector<int>{node->val});
		else out[depth].push_back(node->val);

		dfs(node->left, depth + 1, out);
		dfs(node->right, depth + 1, out);
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> out;
		dfs(root, 0, out);
		return out;
	}
};
// @lc code=end

