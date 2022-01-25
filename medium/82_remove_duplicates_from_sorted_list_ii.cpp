// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem82.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* out = new ListNode(0, head);
		ListNode* node = out;

		while(node->next && node->next->next) {
			if(node->next->val == node->next->next->val) {
				int val = node->next->val;
				// add deletes
				ListNode* next_val_node = node->next->next->next;
				while(next_val_node && next_val_node->val == val) {
					// add deletes
					next_val_node = next_val_node->next;
				}
				node->next = next_val_node;
			}
			else
				node = node->next;
		}

		// add deletes
		return out->next;
	}
};
// @lc code=end

