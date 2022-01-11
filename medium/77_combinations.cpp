// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */


// @lc code=start
class Solution {
	vector<vector<int>> out;

	void back_track(int n, int k, vector<int>& current, int used) {
		if(current.size() == k) out.push_back(current);
		else for(int i = used + 1; i <= n; i++) {
			current.push_back(i);
			back_track(n, k, current, i);
			current.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> curr; curr.reserve(k);
		back_track(n, k, curr, 0);
		return out;
	}
};
// @lc code=end

