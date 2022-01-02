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
[-,-,-,-,-,-,-]

start at: 0 -> 1
[-,-,-,1,-,-,-] tmp: 4   	0+3=3 (mod 7)
[-,-,-,1,-,-,4] tmp: 7   	3+3=6 (mod 7)
[-,-,7,1,-,-,4] tmp: 3   	6+3=2 (mod 7)
[-,-,7,1,-,3,4] tmp: 6 		2+3=5 (mod 7)
[-,6,7,1,-,3,4] tmp: 2		5+3=1 (mod 7)
[-,6,7,1,2,3,4] tmp: 5		1+3=4 (mod 7)
[5,6,7,1,2,3,4] tmp: 1		4+3=0 (mod 7)
end-cycle

[5,6,7,1,2,3,4]
*/

// @lc code=start
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		const int n = nums.size();
		k %= n;
		if(k == 0) return;

		int rotated = 0;
		int start = 0;
		int curr = 0;
		int to_be_rotated = nums[start];
		int tmp = 0;

		while(rotated < n) {
			curr = start;
			do {
				int next = (curr + k) % n;
				tmp = nums[next];
				nums[next] = to_be_rotated;
				to_be_rotated = tmp;
				curr = next;
				rotated++;
			} while(curr != start);

			start++;
			curr = start;
			to_be_rotated = nums[start];
		}
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

