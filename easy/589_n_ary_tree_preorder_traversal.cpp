/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

#include <vector>
#include <stack>

using namespace std;


// @lc code=start
/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Solution {
	// void dfs(Node* node, vector<int>& out) {
	// 	if(!node) return;
	// 	out.push_back(node->val);

	// 	for(int i = 0; i < node->children.size(); i++)
	// 		dfs(node->children[i], out);

	// }

public:
	vector<int> preorder(Node* root) {
		if(!root) return {};

		vector<int> out;

		stack<Node*> s;
		s.push(root);

		while(!s.empty()) {
			Node* node = s.top();
			s.pop();
			out.push_back(node->val);

			for(int i = node->children.size() - 1; i >= 0; i--)
				if(node->children[i])
					s.push(node->children[i]);

		}
		return out;
	}
};
// @lc code=end

