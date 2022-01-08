// @before-stub-for-debug-begin
#include <vector>
#include <string>
//#include "commoncppproblem617.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(!t1) return t2;
		if(!t2) return t1;

		t1->val += t2->val;
		if(t2->left) t1->left = mergeTrees(t1->left, t2->left);
		if(t2->right) t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};
// @lc code=end

