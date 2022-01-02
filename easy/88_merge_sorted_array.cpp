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
		int i = m - 1;
		int j = n - 1;
		while(i >= 0 && j >= 0) {
			if(nums1[i] > nums2[j]) {
				nums1[i + j + 1] = nums1[i];
				--i;
			}
			else { // nums1[i] <= nums2[j])
				nums1[i + j + 1] = nums2[j];
				--j;
			}
		}
		for(; i >= 0; --i) nums1[i + j + 1] = nums1[i];
		for(; j >= 0; --j) nums1[i + j + 1] = nums2[j];
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
