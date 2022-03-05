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
    bool canFlowTo(int i, int j, int curr_height, vector<vector<int>>& heights) {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) {
            return true;
        }
        else return heights[i][j] <= curr_height;
    }

    int bfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& dp) {
        const unsigned m = heights.size();
        const unsigned n = heights[0].size();

        if(i < 0 || j < 0)
            return REACHES_PACIFIC;
        else if(i >= m || j >= n)
            return REACHES_ATLANTIC;

        if(dp[i][j] == REACHES_UNDEFINED) {
            dp[i][j] = REACHES_NONE;
            int height = heights[i][j];

            if(canFlowTo(i + 1, j, height, heights))
                dp[i][j] |= bfs(heights, i + 1, j, dp);

            if(canFlowTo(i, j + 1, height, heights))
                dp[i][j] |= bfs(heights, i, j + 1, dp);

            if(canFlowTo(i - 1, j, height, heights))
                dp[i][j] |= bfs(heights, i - 1, j, dp);

            if(canFlowTo(i, j - 1, height, heights))
                dp[i][j] |= bfs(heights, i, j - 1, dp);

        }
        return dp[i][j];
    }


public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        const int m = heights.size();
        const int n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        vector<vector<int>> out;

        // west and east edge
        for(int i = 0; i < m; i++) {
            if(bfs(heights, i, 0, dp) == REACHES_BOTH)
                out.push_back({ i, 0 });

            if(bfs(heights, m - 1 - i, 0, dp) == REACHES_BOTH)
                out.push_back({ m - 1 - i, 0 });
        }

        // north and south edge
        for(int j = 1; j < n - 1; j++) {
            if(bfs(heights, 0, j, dp) == REACHES_BOTH)
                out.push_back({ 0, j });

            if(bfs(heights, 0, n - 1 - j, dp) == REACHES_BOTH)
                out.push_back({ 0, n - 1 - j });
        }

        // intern tiles
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(bfs(heights, i, j, dp) == REACHES_BOTH)
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
