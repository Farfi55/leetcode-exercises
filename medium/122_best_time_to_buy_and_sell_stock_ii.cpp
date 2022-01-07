// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem122.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();

		int profit = 0;

		int i = 0;
		while(i < n) {
			while(i + 1 < n && prices[i + 1] <= prices[i])i++;
			int buy_price = prices[i];

			while(i + 1 < n && prices[i + 1] >= prices[i])i++;
			int sell_price = prices[i++];

			profit += sell_price - buy_price;
		}

		return profit;
	}
};
// @lc code=end

