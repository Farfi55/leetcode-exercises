/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
	vector<uint64_t> fact_dp{ 1, 1 };
	uint64_t fact(uint64_t n) {
		if(n >= fact_dp.size())
			fact_dp.push_back(n * fact(n - 1));

		return fact_dp[n];
	}
	uint64_t comb(uint64_t n, uint64_t k) {
		return fact(n) / (fact(n - k) * fact(k));
	}

	uint64_t perm(uint64_t n, uint64_t k) {
		return (fact(n + k)) / (fact(k) * fact(n));
	}

public:
	int uniquePaths(int m, int n) {
		return perm(n - 1, m - 1);
	}
};
// @lc code=end

