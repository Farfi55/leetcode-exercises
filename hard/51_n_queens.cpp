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

	bool canAdd(int row, int col, vector<string>& board) {
		 // check col
		for(int i = row; i >= 0; --i)
			if(board[i][col] == 'Q') return false;
		// check left diagonal
		for(int i = row, j = col; i >= 0 && j >= 0; --i, --j)
			if(board[i][j] == 'Q') return false;
		//check right diagonal
		for(int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
			if(board[i][j] == 'Q') return false;
		return true;
	}


	void solve(int n, int row, vector<string>& board, vector<vector<string>>& solutions) {
		if(row == n)
			solutions.push_back(board);
		else for(int col = 0; col < n; col++) {
			if(canAdd(row, col, board)) {
				board[row][col] = 'Q'; // add to current solution
				solve(n, row + 1, board, solutions);
				board[row][col] = '.'; //  from current solution
			}
		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {

		vector<vector<string>> solutions;
		vector<string> board(n, string(n, '.'));
		solve(n, 0, board, solutions);
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
