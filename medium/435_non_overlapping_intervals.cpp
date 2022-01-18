// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
// #include "commoncppproblem435.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
bool comp(vector<int>& a, vector<int>& b) {
	return a[1] < b[1];
}

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), comp);
		int out = 0;
		int pre = 0;
		for(int i = 1; i < intervals.size(); i++) {
			if(intervals[pre][1] > intervals[i][0]) {
				out++;
			}
			else pre = i;
		}
		return out;

	}
};
// @lc code=end

