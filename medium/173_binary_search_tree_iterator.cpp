/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

#include <stack>
#include <vector>

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
class BSTIterator {
	stack<TreeNode*> s;

	void explore_left() {
		TreeNode* curr = s.top();

		while(curr->left) {
			curr = curr->left;
			s.push(curr);
		}
	}

public:
	BSTIterator(TreeNode* root) {
		s.push(root);
		explore_left();
	}

	int next() {
		TreeNode* node = s.top(); s.pop();
		if(node->right) {
			s.push(node->right);
			explore_left();
		}

		return node->val;
	}

	bool hasNext() {
		return !s.empty();
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

