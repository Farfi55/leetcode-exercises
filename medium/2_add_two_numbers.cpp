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
		if(!l1 && !l2) return nullptr;

		ListNode* out_head = l1;
		int carry = 0;

		while(true) {
			if(l2) {
				carry += l2->val;
				l2 = l2->next;
			}

			carry += l1->val;
			l1->val = (carry % 10);
			carry /= 10;
			if(carry || l2) {
				if(!l1->next)
					l1->next = new ListNode();
				l1 = l1->next;
			}
			else
				break;
		}

		return out_head;
	}
};
// @lc code=end

