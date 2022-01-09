// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem83.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode** node = &head;

		while(*node) {
			int val = (*node)->val;
			ListNode* sentinel = (*node)->next;
			while(sentinel && sentinel->val == val)
				sentinel = sentinel->next;
			(*node)->next = sentinel;
			node = &((*node)->next);
		}
		return head;
	}
};
// @lc code=end

