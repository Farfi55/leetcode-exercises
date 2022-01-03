/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */


#include <vector>
#include <queue>
#include <iostream>

using namespace std;


// @lc code=start
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		const int n = nums1.size();
		const int m = nums2.size();

		vector<int> out;
		out.reserve(min(n, m));

		int values1[10001] = { 0 };
		int values2[10001] = { 0 };

		for(int value : nums1) values1[value]++;
		for(int value : nums2) values2[value]++;

		for(int i = 0; i <= 1000; i++) {
			while(values1[i]-- && values2[i]--) out.push_back(i);
		}
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
