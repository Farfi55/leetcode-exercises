/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */


#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;


// @lc code=start
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		const int n = nums1.size();
		const int m = nums2.size();
		if(n > m)
			return intersect(nums2, nums1);

		vector<int> out;
		unordered_map<int, int> dict;

		for(int i = 0; i < n; i++) dict[nums1[i]]++;
		for(int i = 0; i < m; i++)
			if(dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0)
				out.push_back(nums2[i]);
		return out;

	}
};
// @lc code=end


int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums1 = { 1, 2, 2, 1 };
	vector<int> nums2 = { 2,2 };

	auto out = sol.intersect(nums1, nums2);

	for(int value : out)
		cout << value << ", ";
	return 0;
}
