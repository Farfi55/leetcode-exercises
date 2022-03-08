#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {

    vector<int> currPath;
    vector<vector<int>> paths;


    void solve(int node, vector<vector<int>>& graph) {
        currPath.push_back(node);

        if(node == graph.size() - 1)
            paths.push_back(currPath);
        else for(auto next_node : graph[node])
            solve(next_node, graph);

        currPath.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        currPath.reserve(graph.size());

        solve(0, graph);
        return paths;
    }
};
// @lc code=end

