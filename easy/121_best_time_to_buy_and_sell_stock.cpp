/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */


#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int max_profit = 0;
		int min_price = prices[0];

		for(int i = 1; i < n; ++i) {
			min_price = min(min_price, prices[i]);
			max_profit = max(max_profit, prices[i] - min_price);
		}
		return max_profit;
	}
};
// @lc code=end


int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> prices = { 7, 8, 4, 18, 3, 19 };
	auto out = sol.maxProfit(prices);
	cout << out;

	return 0;
}
