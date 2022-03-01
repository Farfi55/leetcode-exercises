#include <vector>

using namespace std;


/*
 * @lc app=leetcode id=1779 lang=cpp
 *
 * [1779] Find Nearest Point That Has the Same X or Y Coordinate
 */

// @lc code=start
class Solution {
public:
	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int min_dist = INT_MAX;
		int min_dist_point = -1;
		for(int i = 0; i < points.size(); i++) {
			if(points[i][0] == x) {
				int dist = abs(y - points[i][1]);
				if(dist < min_dist) {
					min_dist = dist;
					min_dist_point = i;
				}
			}
			else if(points[i][1] == y) {
				int dist = abs(x - points[i][0]);
				if(dist < min_dist) {
					min_dist = dist;
					min_dist_point = i;
				}
			}
		}

		return min_dist_point;
	}
};
// @lc code=end

