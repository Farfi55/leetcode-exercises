// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode** node = &head;
		while(*node) {
			if((**node).val == val)
				*node = (**node).next ? (**node).next : nullptr;
			else
				node = &(**node).next;
		}

		return head;
	}
};
// @lc code=end

