// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>

// #include "commoncppproblem714.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		const size_t n = prices.size();
		if(n <= 1) return 0;

		int sell = 0;
		int buy = -prices[0];

		for(size_t i = 1; i < n; i++) {
			int prev_buy = buy;
			int prev_sell = sell;

			sell = max(prev_buy + prices[i] - fee, prev_sell);
			buy = max(prev_sell - prices[i], prev_buy);

		}
		return sell;
	}
};
// @lc code=end

// int main(int argc, char const* argv[])
// {
// 	vector<int> prices{ 1,3,2,8,4,9 };
// 	int fee = 2;
// 	cout << Solution().maxProfit(prices, fee);
// 	return 0;
// }
