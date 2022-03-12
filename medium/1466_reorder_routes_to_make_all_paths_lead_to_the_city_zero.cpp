#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
    int dfs(int from, vector<vector<int>>& graph, vector<bool>& visited) {
        int flips = 0;
        visited[from] = true;
        for(int to : graph[from])
            if(!visited[abs(to)])
                flips += dfs(abs(to), graph, visited) + (to > 0);
        return flips;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        auto graph = vector<vector<int>>(n);
        for(auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(-conn[0]);
        }

        return dfs(0, graph, visited);
    }



};
// @lc code=end

