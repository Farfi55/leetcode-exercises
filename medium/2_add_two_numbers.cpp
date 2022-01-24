/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;

		if(!l1 && !l2) return nullptr;

		ListNode* out_head = new ListNode();
		ListNode* curr = out_head;

		while(l1 || l2 || carry) {
			int n1 = 0, n2 = 0;
			if(l1) {
				n1 = l1->val;
				l1 = l1->next;
			}
			if(l2) {
				n2 = l2->val;
				l2 = l2->next;
			}

			carry += n1 + n2;

			curr->next = new ListNode(carry % 10);
			curr = curr->next;


			carry /= 10;
		}

		curr = out_head;
		out_head = out_head->next;
		delete curr;
		return out_head;
	}
};
// @lc code=end

