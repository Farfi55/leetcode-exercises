// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
// #include "commoncppproblem653.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
	unordered_set<int> nums;

	bool dfs(TreeNode* node, int k) {
		if(!node) return false;
		if(nums.find(k - node->val) != nums.end())
			return true;
		nums.insert(node->val);
		return dfs(node->left, k) || dfs(node->right, k);
	}
public:
	bool findTarget(TreeNode* root, int k) {
		return dfs(root, k);
	}
};
// @lc code=end

