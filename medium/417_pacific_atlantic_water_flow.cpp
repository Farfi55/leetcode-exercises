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

    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j) {

        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true;
        //up
        if(i - 1 >= 0 && !vis[i - 1][j] && h[i - 1][j] >= h[i][j])
            dfs(h, vis, i - 1, j);
        //down
        if(i + 1 < m && !vis[i + 1][j] && h[i + 1][j] >= h[i][j])
            dfs(h, vis, i + 1, j);
        //left
        if(j - 1 >= 0 && !vis[i][j - 1] && h[i][j - 1] >= h[i][j])
            dfs(h, vis, i, j - 1);
        //right
        if(j + 1 < n && !vis[i][j + 1] && h[i][j + 1] >= h[i][j])
            dfs(h, vis, i, j + 1);

    }


public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        const int m = heights.size();
        const int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for(int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> out;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j])
                    out.push_back({ i,j });
            }
        }
        return out;
    }
};
// @lc code=end


/*

// bool canFlowTo(int i, int j, int curr_height, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
    //     if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) {
    //         return true;
    //     }
    //     else return !visited[i][j] && heights[i][j] <= curr_height;
    // }

    // int bfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& visited) {
    //     const unsigned m = heights.size();
    //     const unsigned n = heights[0].size();

    //     if(i < 0 || j < 0)
    //         return REACHES_PACIFIC;
    //     else if(i >= m || j >= n)
    //         return REACHES_ATLANTIC;

    //     visited[i][j] = true;
    //     if(dp[i][j] == REACHES_UNDEFINED) {
    //         dp[i][j] = REACHES_NONE;
    //         int height = heights[i][j];

    //         if(canFlowTo(i + 1, j, height, heights, visited))
    //             dp[i][j] |= bfs(heights, i + 1, j, dp, visited);

    //         if(canFlowTo(i, j + 1, height, heights, visited))
    //             dp[i][j] |= bfs(heights, i, j + 1, dp, visited);

    //         if(canFlowTo(i - 1, j, height, heights, visited))
    //             dp[i][j] |= bfs(heights, i - 1, j, dp, visited);

    //         if(canFlowTo(i, j - 1, height, heights, visited))
    //             dp[i][j] |= bfs(heights, i, j - 1, dp, visited);

    //     }
    //     return dp[i][j];
    // }


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
