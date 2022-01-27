// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem143.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

#include <vector>

using namespace std;

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
	void reorderList(ListNode* head) {
		ListNode* curr = head->next;
		vector<ListNode*> dq;
		while(curr) {
			dq.push_back(curr);
			curr = curr->next;
		}
		curr = head;
		while(!dq.empty()) {
			curr->next = dq.back();
			dq.pop_back();
			curr = curr->next;
			if(!dq.empty()) {
				curr->next = dq.front();
				curr = curr->next;
				dq.erase(dq.begin());
			}
		}
		curr->next = NULL;
	}


};
// @lc code=end

