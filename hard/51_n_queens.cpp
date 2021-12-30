/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {

	vector<int> queens;
	vector<vector<string>> solutions;

	bool canAdd(int queen_col) {
		int queen_row = queens.size();
		for(int i = 0; i < queen_row; i++) {
			if(queen_col == queens[i] || // same column
				((queen_col - queens[i]) == (queen_row - i)) || // same main diagonal
				((queen_col - queens[i]) == -(queen_row - i))) 	// same secondary diagonal 
				return false;
		}
		return true;

	}

	void addSolution(int n) {
		vector<string> sol;
		for(int i = 0; i < n; i++) {
			sol.push_back(string(queens[i], '.') + 'Q' +
				string(n - queens[i] - 1, '.'));
		}
		solutions.push_back(sol);
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		for(int col = 0; col < n; col++) {
			if(canAdd(col)) {
				queens.push_back(col); // add to current solution

				if(queens.size() == n) addSolution(n); // last queen
				else solveNQueens(n);

				queens.pop_back(); // remove from current solution
			}
		}
		return solutions;
	}

};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	int n; cin >> n;
	auto solutions = sol.solveNQueens(n);
	for(auto& sol : solutions) {
		for(int i = 0; i < n; i++) {
			cout << sol[i] << endl;
		}
		cout << endl << endl;
	}
	return 0;
}
