#include <vector>
#include <queue>
using namespace std;

/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
    struct Path
    {
        int node;
        int dist;
        bool lastRed;

        Path(int node, int dist, bool lastRed) : node(node), dist(dist), lastRed(lastRed) {}
    };

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        auto redGraph = vector<vector<int>>(n, vector<int>{});
        auto blueGraph = vector<vector<int>>(n, vector<int>{});
        auto ans = vector<int>(n, -1);

        for(auto& redEdge : redEdges)
            redGraph[redEdge[0]].push_back(redEdge[1]);

        for(auto& blueEdge : blueEdges)
            blueGraph[blueEdge[0]].push_back(blueEdge[1]);


        auto visitedRed = vector<bool>(n, false);
        auto visitedBlue = vector<bool>(n, false);
        queue<Path> q; q.emplace(0, 0, false);
        visitedRed[0] = true;
        visitedBlue[0] = true;
        while(!q.empty()) {
            Path p = q.front(); q.pop();

            if(ans[p.node] == -1)
                ans[p.node] = p.dist;

            if(!p.lastRed || p.dist == 0)
                for(int redEdge : redGraph[p.node]) {
                    if(!visitedRed[redEdge]) {
                        q.emplace(redEdge, p.dist + 1, true);
                        visitedRed[redEdge] = true;
                    }
                }
            if(p.lastRed || p.dist == 0)
                for(int blueEdge : blueGraph[p.node]) {
                    if(!visitedBlue[blueEdge]) {
                        q.emplace(blueEdge, p.dist + 1, false);
                        visitedBlue[blueEdge] = true;
                    }
                }
        }
        return ans;
    }
};
// @lc code=end

