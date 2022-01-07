// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem1014.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& values) {
		int result = 0;
		int curr = 0;

		// for (size_t i = 0; i < values.size(); i++) {
		for(int& x : values) {
			result = max(curr + x, result);
			curr = max(x, curr) - 1;
		}
		return result;
	}
};
// @lc code=end

