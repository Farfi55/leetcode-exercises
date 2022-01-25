/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		unordered_set<ListNode*> nodes;

		while(headA) {
			nodes.insert(headA);
			headA = headA->next;
		}

		while(headB) {
			if(nodes.count(headB))
				return headB;
			headB = headB->next;
		}

		return nullptr;
	}
};
// @lc code=end

