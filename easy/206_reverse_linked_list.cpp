// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
// #include "commoncppproblem206.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		stack<ListNode*> nodes;

		while(head) {
			nodes.push(head);
			head = head->next;
		}

		if(nodes.empty()) return nullptr;

		ListNode* out = nodes.top();
		ListNode* node = out;
		nodes.pop();

		while(!nodes.empty()) {
			node->next = nodes.top();
			nodes.pop();
			node = node->next;
		}
		node->next = nullptr;
		return out;
	}
};
// @lc code=end

