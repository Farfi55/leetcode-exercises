// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem733.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {

	void dfs(vector<vector<int>>& image, int i, int j, int start_color, int new_color) {
		if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
			return;

		if(image[i][j] != start_color)
			return;

		image[i][j] = new_color;

		dfs(image, i + 1, j, start_color, new_color);
		dfs(image, i - 1, j, start_color, new_color);
		dfs(image, i, j + 1, start_color, new_color);
		dfs(image, i, j - 1, start_color, new_color);

	}

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
		int start_color = image[sr][sc];

		if(start_color != new_color)
			dfs(image, sr, sc, start_color, new_color);

		return image;
	}
};
// @lc code=end

