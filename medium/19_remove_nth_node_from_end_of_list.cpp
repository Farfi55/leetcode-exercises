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

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// double pointer is needed to make changes that apply to
		// the list pointed by head
		ListNode** tail_node = &head;
		ListNode* scout_node = head;

		// we make the scout node advance n-1 times
		for(int i = 1; i < n; i++) {
			scout_node = scout_node->next;
		}

		// then both scout and tail advance
		// untill scout reaches the end of the list
		while(scout_node->next) {
			tail_node = &((*tail_node)->next);
			scout_node = scout_node->next;
		}

		// at this point we assign at the address pointed from tail
		// the address of the next node
		ListNode* tmp = *tail_node;
		*tail_node = (*tail_node)->next;
		delete tmp;
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


