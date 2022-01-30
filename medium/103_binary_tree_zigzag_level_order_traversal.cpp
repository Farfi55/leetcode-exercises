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
		queue<int> q_level;

		q.push(root);
		q_level.push(0);


		while(!q.empty()) {
			int level = q_level.front(); q_level.pop();
			auto node = q.front(); q.pop();

			if(nodes.size() == level)
				nodes.push_back({});

			nodes[level].push_back(node->val);

			if(node->left) {
				q.push(node->left);
				q_level.push(level + 1);
			}
			if(node->right) {
				q.push(node->right);
				q_level.push(level + 1);
			}
		}


		for(int i = 1; i < nodes.size(); i += 2)
			reverse(nodes[i].begin(), nodes[i].end());

		return nodes;
	}
};
// @lc code=end

