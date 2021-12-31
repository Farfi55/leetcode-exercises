/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
	void next(ListNode*& node) {
		node = node->next;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* end = head;

		for(int i = 1; i < n; i++) {
			next(end);
		}
		ListNode* curr = head;

		while(end->next) {
			next(end);
			next(curr);
		}

		curr = n > 1 ? curr->next : nullptr;

		return head;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	cout << "enter nodes: ";
	int x; cin >> x;
	ListNode* head = new ListNode();
	ListNode* node = head;
	while(x != -1) {
		node->next = new ListNode(x);
		node = node->next;
		cin >> x;
	}
	cout << "enter n: ";
	cin >> x;

	node = sol.removeNthFromEnd(head->next, x);

	while(node) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}


