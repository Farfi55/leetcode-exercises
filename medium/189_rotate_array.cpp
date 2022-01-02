/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		const int n = nums.size();
		vector<int> tmp(k, 0);
		for(int i = 0; i < k; i++) tmp[i] = nums[i];
		for(int i = 0; i < n - k; i++) nums[i] = nums[i - k];
		for(int i = 0; i < k; i++) nums[n - k + i] = tmp[i];
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> vec = { 1,2,3,4,5,6,7 };
	sol.rotate(vec, 1);

	for(int x : vec) cout << x << " ";
	cout << endl;
	return 0;
}

