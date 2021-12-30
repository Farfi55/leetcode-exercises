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

	bool canAdd(int row, int col, vector<bool>& cols, vector<bool>& main, vector<bool>& anti) {
		return cols[col] && main[row + col] && anti[row + cols.size() - 1 - col];
	}

	void solve(int n, int row, vector<int>& board, int& solutions,
		vector<bool>& cols, vector<bool>& main, vector<bool>& anti) {
		if(row == n) ++solutions;
		else for(int col = 0; col < n; col++) {
			if(canAdd(row, col, cols, main, anti)) {
				board.push_back(col); // add to current solution
				cols[col] = main[row + col] = anti[row + n - 1 - row] = false;

				solve(n, row + 1, board, solutions, cols, main, anti);

				// remove from current solution
				cols[col] = main[row + col] = anti[row + n - 1 - row] = true;
				board.pop_back();
			}
		}
	}

public:
	int totalNQueens(int n) {
		vector<int> board; board.reserve(n);
		vector<bool> cols(n, true);
		vector<bool> main(n * 2 - 1, true);
		vector<bool> anti(n * 2 - 1, true);
		int solutions = 0;

		solve(n, 0, board, solutions, cols, main, anti);
		return solutions;
	}
};
// @lc code=end

