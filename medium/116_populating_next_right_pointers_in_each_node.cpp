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
	Node* connect(Node* root) {
		if(!root) return nullptr;

		queue<Node*> nodes;
		nodes.push(root);

		int count = 0;
		int nodes_this_level = 1;
		while(!nodes.empty()) {
			Node* node = nodes.front();
			nodes.pop();

			if(++count == nodes_this_level) {
				count = 0;
				nodes_this_level *= 2;
				node->next = nullptr;
			}
			else {
				node->next = nodes.front();
			}

			if(node->left)
				nodes.push(node->left);
			if(node->right)
				nodes.push(node->right);
		}
		return root;
	}
};
// @lc code=end

