// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem112.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
public:
	bool hasPathSum(TreeNode* node, int targetSum) {
		if(!node) return false;
		else {
			targetSum -= node->val;
			if(node->left || node->right)
				return hasPathSum(node->left, targetSum) // ||
				|| hasPathSum(node->right, targetSum);
			else
				return targetSum == 0;
		}
	}
};
// @lc code=end

