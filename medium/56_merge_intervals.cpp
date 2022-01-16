// @before-stub-for-debug-begin
#include <vector>
#include <set>
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
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		set<int> starts;
		set<int> ends;

		for(auto& interval : intervals) {
			starts.insert(interval[0]);
			ends.insert(interval[1]);
		}

		vector<vector<int>> out;
		auto next_start = starts.begin();
		auto next_end = ends.begin();

		while(next_start != starts.end() && next_end != ends.end()) {
			out.push_back({ *next_start, 0 });
			int diff = 0;

			do {
				if(*next_start <= *next_end) {
					next_start++;
					diff++;
					if(next_start == starts.end()) {
						next_end = prev(ends.end());
						break;
					}
				}
				else { // if(*next_start > *next_end) {
					if(--diff > 0)
						next_end++;
				}
				// else {

				// 	next_start++;
				// 	if(diff > 0)
				// 		next_end++;
				// }

			} while(diff > 0);

			out.back()[1] = *next_end;
			next_end++;
		}

		return out;

	}

};
// @lc code=end

