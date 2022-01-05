/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool rows[9][9] = { };
		bool cols[9][9] = { };
		bool sub_boxes[3][3][9] = { };

		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(board[i][j] == '.') continue;
				int val = board[i][j] - '1';

				if(rows[i][val] || cols[j][val] || sub_boxes[i / 3][j / 3][val])
					return false;

				rows[i][val] = cols[j][val] = sub_boxes[i / 3][j / 3][val] = true;
			}
		}

		return true;
	}
};
// @lc code=end


int main(int argc, char const* argv[])
{
	vector<vector<char>> board{
		{'1', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	cout << Solution().isValidSudoku(board);
	return 0;
}
