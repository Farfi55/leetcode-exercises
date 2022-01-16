// @before-stub-for-debug-begin
#include <vector>
#include <set>
#include <algorithm>
#include <string>
// #include "commoncppproblem56.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */


/*
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
	  |--|     |
	  |  |--|
		 |--|

out	  |-----|  |



|-----|  |--|		 |-----|  |-----------|
   |-----------|		|--------|     |--|

|--------------|	 |--------------------|			OUT

STARTS
|  |     |           |  |     |        |
	  |     |  |           |     |        |
diff
1  2  1  2  1  0     1  2  1  2  1     2  0
ENDS


intervals{{0,2}, {1,5}, {3,4}, {7,9}, {8,11}, {10,14}, {13,14}}
out {{0,5}, {7, 14}}
*/




// @lc code=start

// bool interval_sort(const pair<int, int8_t>& lhs, const pair<int, int8_t>& rhs) {
// 	return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
// }


class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int n = intervals.size();

		if(n == 0) return {};

		sort(intervals.begin(), intervals.end());

		vector<vector<int>> out{ intervals[0] };
		for(int i = 1; i < n; i++) {

			if(out.back()[1] >= intervals[i][0]) {
				out.back()[1] = max(out.back()[1], intervals[i][1]);
			}
			else {
				out.push_back(intervals[i]);
			}
		}
		return out;

	}

};
// @lc code=end

