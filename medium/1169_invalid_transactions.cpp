/*
 * @lc app=leetcode id=1169 lang=cpp
 *
 * [1169] Invalid Transactions
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
	struct transaction {
		string t;
		int city_start;
		int time;
		bool valid = true;

		transaction(string& _t, int _start, int _time) :
			t(_t), city_start(_start), time(_time) {}

		string city() {
			return t.substr(city_start);
		}
	};

public:
	vector<string> invalidTransactions(vector<string>& transactions) {
		vector<string> invalids;

		unordered_map<string, vector<transaction>> db;

		for(string& s : transactions) {
			int start = 0;
			int end = s.find(",");
			string name = s.substr(0, end);

			start = end + 1;
			end = s.find(",", start);
			int time = stoi(s.substr(start, end - start));

			start = end + 1;
			end = s.find(",", start);
			int amount = stoi(s.substr(start, end - start));

			string city = s.substr(end + 1);

			bool valid = (amount <= 1000);


			for(transaction& t : db[name]) {
				if(city != t.city() && abs(time - t.time) <= 60) {
					valid = false;
					if(t.valid) {
						t.valid = false;
						invalids.push_back(t.t);
					}
				}
			}

			db[name].push_back(transaction(s, end + 1, time));
			db[name].back().valid = valid;

			if(!valid) invalids.push_back(db[name].back().t);
		}
		return invalids;
	}
};
// @lc code=end

