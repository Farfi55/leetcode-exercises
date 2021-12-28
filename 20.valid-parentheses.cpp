/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <string>
#include <iostream>
#include <stack>

using namespace std;


void print_stack(char c, stack<char> q) {
	cout << c << endl;
	while(!q.empty()) {
		cout << q.top();
		q.pop();
	}
	cout << endl;

}

// @lc code=start
class Solution {
public:
	bool isValid(string s) {

		stack<char> q;

		for(char& c : s) {

			if(c == '(' || c == '[' || c == '{')
				q.push(c);
			else {
				if(q.empty()) return false;
				if(c == ')') {
					if(q.top() != '(')
						return false;
				}
				else if(c == ']') {
					if(q.top() != '[')
						return false;
				}
				else if(c == '}') {
					if(q.top() != '{')
						return false;
				}

				q.pop();
			}
		}
		return q.empty();
	}

};
// @lc code=end


int main(int argc, char const* argv[])
{
	Solution sol;


	string s;
	cin >> s;
	while(s != "exit") {
		cout << sol.isValid(s) << endl;
		cin >> s;
	}

	cin.ignore();
	return 0;
}

