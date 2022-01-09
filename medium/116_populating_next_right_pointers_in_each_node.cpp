// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
// #include "commoncppproblem116.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */


// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

class Solution {
public:
	Node* connect(Node* node) {
		if(!node) return nullptr;

		if(node->left)
			node->left->next = node->right;

		if(node->right && node->next)
			node->right->next = node->next->left;

		connect(node->left);
		connect(node->right);
		return node;
	}
};
// @lc code=end

