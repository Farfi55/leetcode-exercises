/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */


#include <vector>
#include <stack>
#include "../TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	bool find(TreeNode* root, TreeNode* target, stack<TreeNode*>& s) {
		if(!root) return false;

		s.push(root);

		if(root == target) return true;
		else if(find(root->left, target, s)) return true;
		else if(find(root->right, target, s)) return true;

		s.pop();
		return false;
	}

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		stack<TreeNode*> stack_p;
		stack<TreeNode*> stack_q;

		find(root, p, stack_p);
		find(root, q, stack_q);


		while(stack_p.size() > stack_q.size()) stack_p.pop();
		while(stack_p.size() < stack_q.size()) stack_q.pop();

		while(stack_p.top() != stack_q.top()) {
			stack_p.pop();
			stack_q.pop();
		}

		return stack_p.top();
	}
};
// @lc code=end


int main() {

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);

	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(6);

	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(0);


	Solution().lowestCommonAncestor(root, root->left, root->right);
}
