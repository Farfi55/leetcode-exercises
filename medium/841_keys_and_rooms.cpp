/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size();
		vector<bool> has_key(n, false);
		has_key[0] = true;

		int visited = 0;
		queue<int> to_visit;
		to_visit.push(0);

		while(!to_visit.empty()) {
			visited++;
			vector<int>& room = rooms[to_visit.front()];
			to_visit.pop();

			for(int key : room) {
				if(!has_key[key]) {
					has_key[key] = true;
					to_visit.push(key);
				}
			}
		}

		return visited == n;
	}
};
// @lc code=end

