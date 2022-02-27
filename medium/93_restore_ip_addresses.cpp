#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
	bool isValid(string& s, int start, int end) {
		if(end - start > 2 || (s[start] == '0' && start != end)) return false;

		auto val = stoi(s.substr(start, end - start + 1));

		return val < 256;
	}

public:
	vector<string> restoreIpAddresses(string s) {
		const int n = s.size();
		vector<string> out;

		for(int i = 0; i < 3 && i < n - 3; i++) {
			if(!isValid(s, 0, i)) continue;
			for(int j = i + 1; j <= i + 3 && j < n - 2; j++) {
				if(!isValid(s, i + 1, j)) continue;
				for(int k = j + 1; k <= j + 3 && k < n - 1; k++) {
					if(n - k > 6) break;
					if(!isValid(s, j + 1, k) || (!isValid(s, k + 1, n - 1))) continue;

					string ip = s.substr(0, i + 1) + '.' +
						s.substr(i + 1, j - i) + '.' +
						s.substr(j + 1, k - j) + '.' +
						s.substr(k + 1, n - k);
					out.push_back(ip);
				}
			}
		}
		return out;
	}
};
// @lc code=end

