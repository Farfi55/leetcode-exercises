/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> frequence;
		for(char& c : s) {
			frequence[c]++;
		}

		priority_queue<pair<int, char>> pq;


		for(auto& p : frequence) {
			pq.emplace(p.second, p.first);
		}

		string out = "";
		while(!pq.empty()) {

			out += string(pq.top().first, pq.top().second);
			pq.pop();
		}

		return out;

	}
};
// @lc code=end

