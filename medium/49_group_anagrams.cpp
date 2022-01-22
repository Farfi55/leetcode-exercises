/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <vector>
#include <array>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
struct ArrayHasher {
	// from https://stackoverflow.com/a/42701911/6075271

	std::size_t operator()(const std::array<int, 26>& a) const {
		std::size_t h = 0;

		for(auto e : a) {
			h ^= std::hash<int>{}(e)+0x9e3779b9 + (h << 6) + (h >> 2);
		}
		return h;
	}
};

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<array<int, 26>, int, ArrayHasher> map;
		vector<vector<string>> out;

		for(int i = 0; i < strs.size(); i++) {
			array<int, 26> letters;
			letters.fill(0);
			for(char& c : strs[i]) {
				letters[c - 'a']++;
			}

			if(map.find(letters) == map.end()) {
				map[letters] = out.size();
				out.push_back({ strs[i] });
			}
			else {
				out[map[letters]].push_back(strs[i]);
			}
		}

		return out;

	}
};
// @lc code=end

