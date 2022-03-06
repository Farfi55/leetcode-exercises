#include <queue>
#include <tuple>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {

    bool tryExplore(unsigned i, unsigned j, int dist, vector<vector<int>>& grid, queue<tuple<unsigned, unsigned, int>>& q, vector<vector<bool>>& vis) {
        if(i >= grid.size() || j >= grid.size() || grid[i][j] == 1 || vis[i][j])
            return false;

        q.emplace(i, j, dist);
        vis[i][j] = true;

        return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<tuple<unsigned, unsigned, int>> q;
        q.emplace(0, 0, 1);

        vector<vector<bool>> vis(n, vector<bool>(n));
        vis[0][0] = true;

        while(!q.empty()) {
            unsigned i = get<0>(q.front());
            unsigned j = get<1>(q.front());
            int dist = get<2>(q.front());
            q.pop();

            if(i == n - 1 && j == n - 1)
                return dist;

            tryExplore(i + 1, j + 1, dist + 1, grid, q, vis);   // SE
            tryExplore(i + 1, j, dist + 1, grid, q, vis);       // S
            tryExplore(i + 1, j - 1, dist + 1, grid, q, vis);   // SW

            tryExplore(i, j + 1, dist + 1, grid, q, vis);       // E
            tryExplore(i - 1, j + 1, dist + 1, grid, q, vis);   // NE

            tryExplore(i - 1, j, dist + 1, grid, q, vis);       // N
            tryExplore(i, j - 1, dist + 1, grid, q, vis);       // W
            tryExplore(i - 1, j - 1, dist + 1, grid, q, vis);   // NW
        }

        return -1;
    }
};
// @lc code=end

