/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start

class Solution {
public:
	void swap(ListNode* a, ListNode* b) {
		int tmp = a->val;
		a->val = b->val;
		b->val = tmp;
	}

	ListNode* swapPairs(ListNode* head) {
		ListNode* node = head;
		while(node && node->next) {
			swap(node, node->next);
			node = node->next->next;
		}
		return head;
	}
};
// @lc code=end

