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
public:
	void pushLeft(stack<TreeNode*>& s, TreeNode* n) {
		while(n != nullptr) {
			s.push(n);
			n = n->left;
		}
	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> res;
		stack<TreeNode*> s1, s2;
		pushLeft(s1, root1);
		pushLeft(s2, root2);
		while(!s1.empty() || !s2.empty()) {
			stack<TreeNode*>* s;

			if(s1.empty()) s = &s2;
			else if(s2.empty()) s = &s1;
			else {
				s = (s1.top()->val < s2.top()->val) ? &s1 : &s2;
			}

			TreeNode* n = s->top(); s->pop();
			res.push_back(n->val);
			pushLeft(*s, n->right);
		}
		return res;
	}
};
// @lc code=end

