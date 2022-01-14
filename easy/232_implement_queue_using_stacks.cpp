/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <stack>

using namespace std;


// @lc code=start
class MyQueue {
	stack<int> s;
public:
	MyQueue() {}

	void push(int x) {
		stack<int> tmp;
		while(!s.empty()) {
			tmp.push(pop());
		}

		s.push(x);

		while(!tmp.empty()) {
			s.push(tmp.top());
			tmp.pop();
		}
	}

	int pop() {
		int x = s.top();
		s.pop();
		return x;
	}

	int peek() {
		return s.top();
	}

	bool empty() {
		return s.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

