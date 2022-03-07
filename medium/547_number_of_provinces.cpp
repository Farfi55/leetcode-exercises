#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int islands = 0;
        queue<int> to_explore;



        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;

            islands++;
            to_explore.push(i);

            while(!to_explore.empty()) {
                int  k = to_explore.front();to_explore.pop();

                for(int j = 0; j < n; j++) {
                    if(j != i && !visited[j] && isConnected[k][j]) {
                        to_explore.push(j);
                        visited[j] = true;
                    }
                }
            }

        }

        return islands;
    }
};
// @lc code=end

