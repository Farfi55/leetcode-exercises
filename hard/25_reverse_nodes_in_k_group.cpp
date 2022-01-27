/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

#include <stack>
#include <vector>

using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode* next) : val(x), next(next) {}

// };

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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(head == nullptr || k == 1) return head;

		ListNode sentinel = ListNode(0, head);

		ListNode* curr = &sentinel;
		ListNode* next;
		ListNode* prev = &sentinel;

		int remaining_nodes = 0;
		while(curr = curr->next)
			remaining_nodes++;

		while(remaining_nodes >= k) {
			curr = prev->next;
			next = curr->next;
			for(int i = 1; i < k; ++i) {
				curr->next = next->next;
				next->next = prev->next;
				prev->next = next;
				next = curr->next;
			}

			prev = curr;
			remaining_nodes -= k;
		}

		return sentinel.next;
	}
};
// @lc code=end

