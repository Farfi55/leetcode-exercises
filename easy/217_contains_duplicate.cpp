/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, bool> hash_map;
		for(int num : nums) {
			if(hash_map.find(num) != hash_map.end()) return true;
			else hash_map[num] = true;
		}
		return false;
	}
};
// @lc code=end

