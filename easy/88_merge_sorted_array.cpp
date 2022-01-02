/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> tmp(n + m, 0);
		int i = 0, j = 0;
		while(i < m && j < n) {
			if(nums1[i] < nums2[j])
				tmp[i++ + j] = nums1[i];
			else
				tmp[i + j++] = nums2[j];
		}
		while(i < m) tmp[i++ + j] = nums1[i];
		while(j < n) tmp[i + j++] = nums2[j];
		for(int i = 0; i < n + m; i++) {
			nums1[i] = tmp[i];
		}

	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	sol.merge(nums1, 3, nums2, 3);

	for(int x : nums1) {
		cout << x << " ";
	}
	return 0;
}
