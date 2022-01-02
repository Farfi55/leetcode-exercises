/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
[1,2,3,4,5,6,7] k = 3, n = 7

[1,2,3,4,5,6,7] IN
|-------------| reverse (0...n) -> range(0,7)
[7,6,5,4,3,2,1]
|-----|			reverse (0...k) -> range(0,3)
[5,6,7,4,3,2,1]
	  |-------|	reverse (k...n) -> range(3,7)
[5,6,7,1,2,3,4] OUT


same as
[1,2,3,4,5,6,7]

[1,2,3,4,5,6,7]	IN
|-------|		reverse (0...n-k) -> range(0, 4)
[4,3,2,1,5,6,7]
		|-----|	reverse (n-k...n) -> range(4, 7)
[4,3,2,1,7,6,5]
|-------------| reverse (0...n)   -> range(0, 7)
[5,6,7,1,2,3,4] OUT
*/

// @lc code=start
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();

		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());

		// or

		// reverse(nums.begin(), nums.end() - k);
		// reverse(nums.end() - k, nums.end());
		// reverse(nums.begin(), nums.end());

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

