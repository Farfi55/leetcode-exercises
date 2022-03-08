/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root, bool isLeftChild) {
        if(!root)
            return 0;

        if(!root->left && !root->right)
            return isLeftChild ? root->val : 0;
        else
            return sumOfLeftLeaves(root->left, true) +
            sumOfLeftLeaves(root->right, false);
    }


public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
};
// @lc code=end

