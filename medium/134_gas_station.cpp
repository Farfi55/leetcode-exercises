// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem134.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		const int n = gas.size();

		int start = 0;
		int fuel = 0;
		int total = 0;

		for(int i = 0; i < n; i++) {
			fuel += gas[i] - cost[i];
			if(fuel < 0) {
				start = i + 1;
				total += fuel;
				fuel = 0;
			}
		}

		return (total + fuel < 0) ? -1 : start;
	}
};
// @lc code=end

