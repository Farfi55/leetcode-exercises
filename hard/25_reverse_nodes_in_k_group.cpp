// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

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
		ListNode* sentinel = new ListNode(0, head);

		ListNode* curr = sentinel;

		while(1) {
			ListNode* idk = curr->next;
			stack<ListNode*> s;

			for(int i = 0; i < k && idk != nullptr; i++) {
				s.push(idk);
				idk = idk->next;
			}

			if(s.size() != k) break;

			while(!s.empty()) {
				curr->next = s.top();
				s.pop();
				curr = curr->next;
			}
			curr->next = idk;

		}

		auto tmp = sentinel->next;
		delete sentinel;
		return tmp;
	}
};
// @lc code=end

