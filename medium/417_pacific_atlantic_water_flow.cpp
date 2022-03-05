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

#define REACHES_BOTH 3
#define REACHES_ATLANTIC 2
#define REACHES_PACIFIC 1
#define REACHES_NONE 0
#define REACHES_UNDEFINED -1
class Solution {
    bool canFlowTo(int i, int j, int curr_height, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) {
            return true;
        }
        else return !visited[i][j] && heights[i][j] <= curr_height;
    }

    int bfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& visited) {
        const unsigned m = heights.size();
        const unsigned n = heights[0].size();

        if(i < 0 || j < 0)
            return REACHES_PACIFIC;
        else if(i >= m || j >= n)
            return REACHES_ATLANTIC;

        visited[i][j] = true;
        if(dp[i][j] == REACHES_UNDEFINED) {
            dp[i][j] = REACHES_NONE;
            int height = heights[i][j];

            if(canFlowTo(i + 1, j, height, heights, visited))
                dp[i][j] |= bfs(heights, i + 1, j, dp, visited);

            if(canFlowTo(i, j + 1, height, heights, visited))
                dp[i][j] |= bfs(heights, i, j + 1, dp, visited);

            if(canFlowTo(i - 1, j, height, heights, visited))
                dp[i][j] |= bfs(heights, i - 1, j, dp, visited);

            if(canFlowTo(i, j - 1, height, heights, visited))
                dp[i][j] |= bfs(heights, i, j - 1, dp, visited);

        }
        return dp[i][j];
    }


public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        const int m = heights.size();
        const int n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(m, REACHES_UNDEFINED));
        vector<vector<int>> out;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(m, false));
                if(bfs(heights, i, j, dp, visited) == REACHES_BOTH)
                    out.push_back({ i,j });
            }
        }
        return out;
    }
};
// @lc code=end


/*
vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[start_i][start_j] = true;

            queue<pair<int, int>> q;
            q.emplace(start_i, start_j);

            while(!q.empty() && !(reaches_pacific && reaches_atlantic)) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();


                int curr_height = heights[i][j];
                if(canFlowTo(i + 1, j, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                    visited[i + 1][j] = true;
                    q.emplace(i + 1, j);
                }
                if(canFlowTo(i, j + 1, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                    visited[i][j + 1] = true;
                    q.emplace(i, j + 1);
                }
                if(canFlowTo(i - 1, j, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                    visited[i - 1][j] = true;
                    q.emplace(i - 1, j);
                }
                if(canFlowTo(i, j - 1, curr_height, heights, visited, reaches_pacific, reaches_atlantic)) {
                    visited[i][j - 1] = true;
                    q.emplace(i, j - 1);
                }
            }
            */
