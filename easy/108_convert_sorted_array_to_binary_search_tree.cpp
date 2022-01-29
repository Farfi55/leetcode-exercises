/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
	TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
		if(i > j)
			return nullptr;

		int mid = (i + j + 1) / 2;
		TreeNode* node = new TreeNode(nums[mid]);

		node->left = sortedArrayToBST(nums, i, mid - 1);
		node->right = sortedArrayToBST(nums, mid + 1, j);

		return node;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
};
// @lc code=end

