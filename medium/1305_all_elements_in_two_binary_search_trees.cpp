/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 */

#include <vector>
#include <stack>
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
	void inorder(TreeNode* node, vector<int>& nums) {
		if(!node) return;

		inorder(node->left, nums);
		nums.push_back(node->val);
		inorder(node->right, nums);
	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> l1;
		vector<int> l2;
		inorder(root1, l1);
		inorder(root2, l2);

		vector<int> out(l1.size() + l2.size());
		merge(l1.begin(), l1.end(), l2.begin(), l2.end(), out.begin());
		return out;
	}
};
// @lc code=end

