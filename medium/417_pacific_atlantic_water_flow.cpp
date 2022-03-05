// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem417.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
    bool canGoTo(int i, int j, int curr_height, vector<vector<int>>& heights, vector<vector<bool>>& visited, bool& reaches_pacific, bool& reaches_atlantic) {
        if(i < 0 || j < 0) {
            reaches_pacific = true;
            return false;
        }
        else if(i >= heights.size() || j >= heights[0].size()) {
            reaches_atlantic = true;
            return false;
        }
        else return !visited[i][j] && heights[i][j] <= curr_height;
    }

    bool bfs(vector<vector<int>>& heights, int start_i, int start_j) {
        const unsigned m = heights.size();
        const unsigned n = heights[0].size();

        bool reaches_pacific = false;
        bool reaches_atlantic = false;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[start_i][start_j] = true;

        queue<pair<int, int>> q;
        q.emplace(start_i, start_j);

        while(!q.empty() && !(reaches_pacific && reaches_atlantic)) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();


            int curr_height = heights[i][j];
            if(canGoTo(i + 1, j, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                visited[i + 1][j] = true;
                q.emplace(i + 1, j);
            }
            if(canGoTo(i, j + 1, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                visited[i][j + 1] = true;
                q.emplace(i, j + 1);
            }
            if(canGoTo(i - 1, j, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                visited[i - 1][j] = true;
                q.emplace(i - 1, j);
            }
            if(canGoTo(i, j - 1, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                visited[i][j - 1] = true;
                q.emplace(i, j - 1);
            }
        }

        return reaches_pacific && reaches_atlantic;

    }





public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> out;

        const unsigned m = heights.size();
        const unsigned n = heights[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(bfs(heights, i, j))
                    out.push_back({ i, j });

        return out;
    }
};
// @lc code=end

