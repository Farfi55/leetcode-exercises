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
	void addRecursive(ListNode* node, int carry) {
		carry += node->val;
		node->val = carry % 10;
		carry /= 10;
		if(carry) {
			if(!node->next)
				node->next = new ListNode(carry);
			else
				addRecursive(node->next, carry);
		}
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
		if(!l1 && !l2) return nullptr;
		else if(!l1) {
			addRecursive(l2, carry);
			return l2;
		}
		else if(!l2) {
			addRecursive(l1, carry);
			return l1;
		}

		carry += l1->val + l2->val;
		auto out = new ListNode(carry % 10);
		out->next = addTwoNumbers(l1->next, l2->next, carry / 10);
		return out;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return addTwoNumbers(l1, l2, 0);
	}
};
// @lc code=end

