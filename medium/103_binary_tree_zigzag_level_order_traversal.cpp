/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if(!root)
			return {};

		vector<vector<int>> nodes;

		queue<TreeNode*> q;

		q.push(root);

		bool left_to_right = true;

		while(!q.empty()) {

			int sz = q.size();
			vector<int> curr(sz);

			for(int i = 0; i < sz; i++) {
				auto node = q.front(); q.pop();

				if(left_to_right)
					curr[i] = node->val;
				else curr[sz - 1 - i] = node->val;

				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);

			}

			nodes.push_back(curr);

			left_to_right = !left_to_right;
		}


		return nodes;
	}
};
// @lc code=end

