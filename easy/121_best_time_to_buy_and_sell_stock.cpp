/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */


#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();

		// brute force
		int max_diff = 0;
		for(int i = 0; i < n; i++) {
			for(int j = n - 1; j > i; j--) {
				if(prices[j] - prices[i] > max_diff)
					max_diff = prices[j] - prices[i];
			}
		}

		return max_diff;

	}
};
// @lc code=end


int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> prices = { 5, 15, 75 };
	auto out = sol.maxProfit(prices);
	cout << out;

	return 0;
}
