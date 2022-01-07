// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
// #include "commoncppproblem141.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	bool hasCycle(ListNode* head) {
		unordered_set<size_t> nodes_addr;

		while(head) {
			size_t addr = reinterpret_cast<size_t>(head);

			if(nodes_addr.find(addr) != nodes_addr.end())
				return true;
			nodes_addr.insert(addr);
			head = head->next;
		}
		return false;
	}
};
// @lc code=end

