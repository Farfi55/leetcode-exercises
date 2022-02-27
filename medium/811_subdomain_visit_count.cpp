#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */

// @lc code=start
class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, unsigned> domains;
		for(string& domain : cpdomains) {

			auto separator = domain.find(' ');
			unsigned count = stoi(domain.substr(0, separator));

			while(separator != -1) {
				domain = domain.erase(0, separator + 1);
				domains[domain] += count;
				separator = domain.find('.');
			}
		}

		vector<string> out;
		for(auto& domain : domains) {
			out.push_back(to_string(domain.second) + " " + domain.first);
		}
		return out;
	}
};
// @lc code=end

