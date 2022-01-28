/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <vector>

using namespace std;

// @lc code=start
class MinStack : protected vector<int> {
	int min_val = INT_MAX;
	int min_val_height = -1;

	void find_new_min() {

		if(size() == 0) {
			min_val_height = -1;
			return;
		}

		min_val_height = 0;
		min_val = operator[](0);
		for(int i = 1; i < size(); i++) {
			if(operator[](i) < min_val) {
				min_val = operator[](i);
				min_val_height = i;
			}
		}
	}

public:
	MinStack() : vector<int>() {}

	void push(int val) {
		this->push_back(val);
		if(min_val_height == -1 || val < min_val) {
			min_val = val;
			min_val_height = size();
		}
	}

	void pop() {
		pop_back();
		if(min_val_height >= size())
			find_new_min();
	}

	int top() {
		return back();
	}

	int getMin() {
		return min_val;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

