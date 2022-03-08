#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
    void solve(int node, vector<int>& currPath, vector<vector<int>>& graph, vector<vector<int>>& paths) {
        currPath.push_back(node);
        if(node == graph.size() - 1) {
            paths.push_back(currPath);
        }
        else for(int i = 0; i < graph[node].size(); i++) {
            solve(graph[node][i], currPath, graph, paths);
        }

        currPath.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> currPath; currPath.reserve(graph.size());

        solve(0, currPath, graph, paths);
        return paths;
    }
};
// @lc code=end

