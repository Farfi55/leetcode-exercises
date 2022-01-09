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
		stack<int> nodes_values;
		ListNode* node = head;

		while(node) {
			nodes_values.push(node->val);
			node = node->next;
		}
		node = head;
		while(!nodes_values.empty()) {
			node->val = nodes_values.top();
			nodes_values.pop();
			node = node->next;
		}

		return head;
	}
};
// @lc code=end

