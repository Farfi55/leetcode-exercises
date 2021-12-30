/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
#include <vector>

using namespace std;
// @lc code=start

class Solution {
public:

	vector<int> board;
	int solutions = 0;

	bool canAdd(int queen_col) {
		int queen_row = board.size();
		for(int i = 0; i < queen_row; i++) {
			if(queen_col == board[i] || // same column
				((queen_col - board[i]) == (queen_row - i)) || // same main diagonal
				((queen_col - board[i]) == -(queen_row - i))) 	// same secondary diagonal 
				return false;
		}
		return true;

	}

public:
	int totalNQueens(int n) {
		for(int col = 0; col < n; col++) {
			if(canAdd(col)) {
				board.push_back(col); // add to current solution

				if(board.size() == n) solutions++; // last queen
				else totalNQueens(n);

				board.pop_back(); // remove from current solution
			}
		}
		return solutions;
	}
};
// @lc code=end

