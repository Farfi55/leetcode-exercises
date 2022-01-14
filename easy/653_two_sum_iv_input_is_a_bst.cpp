// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
// #include "commoncppproblem653.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
	bool findTarget(TreeNode* root, int target) {
		if(!root) return false;


		stack<TreeNode*> sl; // stack left		
		stack<TreeNode*> sr; // stack right

		TreeNode* nl = root; // node left
		TreeNode* nr = root; // node right


		while(1) {
			while(nl) {
				sl.push(nl);
				nl = nl->left;
			}

			while(nr) {
				sr.push(nr);
				nr = nr->right;
			}

			if(sl.empty() || sr.empty()) break;

			nl = sl.top();
			nr = sr.top();

			int sum = (nl->val + nr->val);

			if(sum < target) {
				sl.pop();
				nl = nl->right;
				nr = NULL;
			}
			else if(sum > target) {
				sr.pop();
				nr = nr->left;
				nl = NULL;
			}
			else { // (sum == target) 
				if(nl == nr) return false;

				return true;
			}
		}
		return false;

	}
};
// @lc code=end

