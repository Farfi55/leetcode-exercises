/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


// https://leetcode.com/problems/jump-game-iv/discuss/502699/JavaC%2B%2B-BFS-Solution-Clean-code-O(N)

// @lc code=start
class Solution {
public:
	int minJumps(vector<int>& arr) {
		int n = arr.size();
		unordered_map<int, vector<int>> indicesOfValue;

		vector<bool> visited(n); visited[0] = true;

		queue<int> q; q.push(0);

		// we store indices of same values together to
		// facilitate moving through them
		for(int i = 0; i < n; i++) {
			indicesOfValue[arr[i]].push_back(i);
		}

		int jumps = 0;

		while(!q.empty()) {

			for(int size = q.size(); size > 0; --size) {
				int i = q.front(); q.pop();

				if(i == n - 1) return jumps; // Reached to last index

				vector<int>& next = indicesOfValue[arr[i]];
				next.push_back(i - 1);
				next.push_back(i + 1);

				for(int j : next) {
					if(j >= 0 && j < n && !visited[j]) {
						visited[j] = true;
						q.push(j);
					}
				}
				next.clear(); // avoid later lookup indicesOfValue arr[i]
			}
			jumps++;
		}
		return 0;

	}
};
// @lc code=end

