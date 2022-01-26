/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 */

#include <array>
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
	void dfs(TreeNode* node, array<int, 5001>& nums) {
		if(!node) return;

		dfs(node->left, nums);
		nums[node->val]++;
		dfs(node->right, nums);
	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		array<int, 5001> nums;
		nums.fill(0);

		dfs(root1, nums);
		dfs(root2, nums);

		vector<int>out;
		for(int i = 0; i <= 5000; i++) {
			while(nums[i]--)
				out.push_back(i);
		}


		return out;
	}
};
// @lc code=end

