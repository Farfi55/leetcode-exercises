/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <cmath>
#include <vector>

using namespace std;

// vector<uint64_t> fact_dp{ 1, 1 };
// uint64_t fact(uint64_t n) {
// 	if(n >= fact_dp.size())
// 		fact_dp.push_back(n * fact(n - 1));

// 	return fact_dp[n];
// }
// uint64_t comb(uint64_t n, uint64_t k) {
// 	return fact(n) / (fact(n - k) * fact(k));
// }

// uint64_t perm(uint64_t n, uint64_t k) {
// 	return (fact(n + k)) / (fact(k) * fact(n));
// }

/*
	(3 + 7)!
	10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1

	7!
				 7 * 6 * 5 * 4 * 3 * 2 * 1

	(3+7)! / 7!
	10 * 9 * 8

	(3+7)! / (7! * 3!)
	10 * 9 * 8 / ( 3 * 2 * 1)

*/

// @lc code=start
class Solution {

public:
	int uniquePaths(int m, int n) {
		if(m == 1 || n == 1) return 1;

		// make sure that m >= n
		if(m < n) return uniquePaths(n, m);

		m--; n--;

		uint64_t res = 1;

		for(int i = m + 1, j = 1; j <= n; i++, j++) {
			res *= i;
			res /= j;
		}

		return res;
	}
};
// @lc code=end

