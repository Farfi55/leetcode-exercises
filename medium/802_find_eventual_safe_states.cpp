#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {

    bool dfs(int i, vector<vector<int>>& graph, vector<int>& isSafe, vector<bool>& vis) {
        if(isSafe[i] == -1) {
            vis[i] = true;
            for(int node : graph[i]) {
                if(isSafe[node] != 1 &&
                    (vis[node] || !dfs(node, graph, isSafe, vis)))
                    return isSafe[i] = 0;
            }
            isSafe[i] = 1;
        }
        return isSafe[i];
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> isSafe(n, -1);

        for(int i = 0; i < n; i++)
            if(graph[i].size() == 0)
                isSafe[i] = 1;


        for(int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            if(isSafe[i] == -1)
                isSafe[i] = dfs(i, graph, isSafe, vis);
        }

        vector<int> out;
        for(int i = 0; i < n; i++)
            if(isSafe[i])
                out.push_back(i);
        return out;


    }
};
// @lc code=end

