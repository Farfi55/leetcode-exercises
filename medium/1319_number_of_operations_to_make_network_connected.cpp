#include <vector>
#include <queue>
using namespace std;

/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;

        auto graph = vector<vector<int>>(n, vector<int>{});

        for(auto& connection : connections) {
            int a = connection[0];
            int b = connection[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int islands = 0;
        auto visited = vector<bool>(n, false);

        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            visited[i] = true;
            islands++;

            queue<int> node_queue; node_queue.emplace(i);
            while(!node_queue.empty()) {
                auto node = node_queue.front(); node_queue.pop();
                for(auto other_node : graph[node]) {
                    if(!visited[other_node]) {
                        visited[other_node] = true;
                        node_queue.emplace(other_node);
                    }
                }
            }
        }
        return islands - 1;

    }
};
// @lc code=end

