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

		for(int i = 0; i < n; i++) {
			int fuel = 0;
			bool completed = true;
			for(int j = i; j < n + i; j++) {
				fuel += gas[j % n] - cost[j % n];
				if(fuel < 0) {
					completed = false;
					break;
				}
			}

			if(completed)
				return i;
		}
		return -1;

	}
};
// @lc code=end

