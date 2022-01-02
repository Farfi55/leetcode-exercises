/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

#include <vector>
#include <iostream>

using namespace std;

/*
[1,2,3,4,5,6,7] k = 3, n = 7
[5,6,7]
[-,-,-,1,2,3,4]
[5,6,7,1,2,3,4]
*/

// @lc code=start
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		const int n = nums.size();
		k %= n;
		if(k == 0) return;

		vector<int> tmp(k, 0);

		for(int i = 0; i < k; i++)
			tmp[i] = nums[n - k + i];

		for(int i = n - 1; i >= k; --i)
			nums[i] = nums[i - k];

		for(int i = 0; i < k; i++)
			nums[i] = tmp[i];
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> vec = { 1, 2, 3 };

	// for(int i = 0; i < 3; i++) {
	sol.rotate(vec, 2);
	for(int x : vec) cout << x << " ";
	cout << endl;
// }
	return 0;
}

