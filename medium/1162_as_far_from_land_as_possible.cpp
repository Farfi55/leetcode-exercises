#include <queue>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const unsigned m = grid.size();
        const unsigned n = grid[0].size();
        int max_dist = 0;

        queue<tuple<unsigned, unsigned, int>> q;
        for(unsigned i = 0; i < m; i++)
            for(unsigned j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.emplace(i, j, 1);
                }
            }


        while(!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int dist = get<2>(q.front());
            q.pop();


            if(i >= m || j >= n || grid[i][j] > 1) continue;


            if(grid[i][j] == 0 || dist == 1) {
                if(grid[i][j] == 0) {
                    grid[i][j] = dist;
                    max_dist = max(max_dist, dist);
                }

                q.emplace(i + 1, j, dist + 1);
                q.emplace(i, j + 1, dist + 1);
                q.emplace(i - 1, j, dist + 1);
                q.emplace(i, j - 1, dist + 1);
            }


        }
        return max_dist - 1;
    }
};
// @lc code=end

