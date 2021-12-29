/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* list_start = new ListNode();
		ListNode* list = list_start;

		while(list2 && list1) {

			if(list2->val < list1->val) {
				list->next = new ListNode(list2->val);
				list2 = list2->next;
			}
			else {
				list->next = new ListNode(list1->val);
				list1 = list1->next;
			}
			list = list->next;
		}


		while(list1) {
			list->next = new ListNode(list1->val);
			list1 = list1->next;
			list = list->next;
		}

		while(list2) {
			list->next = new ListNode(list2->val);
			list2 = list2->next;
			list = list->next;
		}

		return list_start->next;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	int x;
	cin >> x;
	ListNode* l1;
	ListNode* l1_curr = l1;
	ListNode* l2;
	ListNode* l2_curr = l2;
	while(x != -1) {
		l1_curr->next = new ListNode(x);
		l1_curr = l1_curr->next;
		cin >> x;
	}
	cin >> x;
	while(x != -1) {
		l2_curr->next = new ListNode(x);
		l2_curr = l2_curr->next;
		cin >> x;
	}


	ListNode* out = sol.mergeTwoLists(l1->next, l2->next);

	cout << out->val << " ";

	while(out->next) {
		out = out->next;
		cout << out->val << " ";
	}

	return 0;
}



