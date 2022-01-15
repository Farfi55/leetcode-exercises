/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
	int minJumps(vector<int>& arr) {
		int n = arr.size();
		unordered_map<int, int> hash;
		vector<int> dp(n, INT_MAX);
		dp[0] = 0;
		hash[arr[0]] = 0;

		for(int i = 1; i < n; i++) {
			dp[i] = dp[i - 1] + 1;
			if(hash.find(arr[i]) != hash.end()) {
				dp[i] = min(dp[i], hash[arr[i]] + 1);
				hash[arr[i]] = min(hash[arr[i]], dp[i]);
			}
			else
				hash[arr[i]] = dp[i];

		}

		bool changed = false;
		do {
			for(int i = n - 2; i >= 0; --i) {
				if(min(dp[i + 1], hash[arr[i]]) + 1 < dp[i]) {
					changed = true;
					dp[i] = min(dp[i + 1], hash[arr[i]]) + 1;
					hash[arr[i]] = min(hash[arr[i]], dp[i]);
				}
			}

			if(!changed) break;
			changed = false;

			for(int i = 1; i < n; i++) {
				if(min(dp[i - 1], hash[arr[i]]) + 1 < dp[i]) {
					changed = true;
					dp[i] = min(dp[i - 1], hash[arr[i]]) + 1;
					hash[arr[i]] = min(hash[arr[i]], dp[i]);
				}
			}

		} while(changed);


		return dp[n - 1];

	}
};
// @lc code=end

