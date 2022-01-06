/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

// @lc code=start
class Solution {
public:
	// int minCost(vector<int>& cuts, int start, int end, int i, int j) {
	// 	const int stick_length = end - start;

	// 	// base case
	// 	if(stick_length <= 1 || i > j) return 0;

	// 	// find the cut closest to the center of this block
	// 	// divide the problem into 2 sub problems and 
	// 	// call this function recursively
	// 	int _i = i;
	// 	int _j = j;
	// 	int cut_idx = 0;
	// 	int target_cut = stick_length / 2;

	// 	while(i <= j) {
	// 		int mid = cut_idx = (i + j) / 2;
	// 		if(cuts[mid] < target_cut) i = mid + 1;
	// 		else if(cuts[mid] > target_cut) j = mid - 1;
	// 		else {
	// 			cut_idx = (i + j) / 2;
	// 			break;
	// 		}
	// 	}

	// 	int cut = cuts[cut_idx];
	// 	return stick_length + minCost(cuts, start, cut, _i, cut_idx - 1) +
	// 		minCost(cuts, cut, end, cut_idx + 1, _j);
	// }

	// int dfs(vector<int>& cuts, int i, int j) {
	// 	if(j - i <= 1) return 0;

	// 	if(!dp[i][j]) {
	// 		dp[i][j] = INT_MAX;
	// 		for(auto k = i + 1; k < j; ++k)
	// 			dp[i][j] = min(dp[i][j],
	// 				(cuts[j] - cuts[i]) + dfs(cuts, i, k) + dfs(cuts, k, j));
	// 	}
	// 	return dp[i][j];
	// }

	int minCost(int n, vector<int>& cuts) {
		// we add 0 and n as cuts
		cuts.push_back(0);
		cuts.push_back(n);
		// we sort the cuts
		sort(begin(cuts), end(cuts));

		const int n_cuts = cuts.size();

		vector<vector<int>> dp(n_cuts, vector<int>(n_cuts, 0));

		for(int i = 0; i < n_cuts; i++) {
			// this makes it bottom-up 
			// because we always process the smaller cuts first
			for(int j = i - 1; j >= 0; j--) {
				for(int k = j + 1; k < i; k++) {
					dp[j][i] = min(dp[j][i] ? dp[j][i] : INT_MAX,
						(cuts[i] - cuts[j]) + dp[j][k] + dp[k][i]);

				}

			}
		}
		return dp[0][n_cuts - 1];

	}

};
// @lc code=end


int main(int argc, char const* argv[])
{
	int n = 7;
	vector<int> cuts{ 1, 3, 4, 5 };
	cout << Solution().minCost(n, cuts);
	return 0;
}

