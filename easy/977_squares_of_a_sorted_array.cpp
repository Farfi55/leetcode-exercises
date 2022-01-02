/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
	int find_lowest_abs(vector<int>& nums) {
		// this can for sure be made better than O(n)
		int n = nums.size();
		int min_abs_idx = 0;
		int min_abs = abs(nums[0]);
		for(int i = 1; i < n; i++) {
			if(abs(nums[i]) < min_abs) {
				min_abs_idx = i;
				min_abs = abs(nums[i]);
			}
			else if(0 <= nums[i - 1] && nums[i - 1] < nums[i]) {
				break;
			}
		}
		return min_abs_idx;
	}


public:
	vector<int> sortedSquares(vector<int>& nums) {
		int n = nums.size();
		int lowest_abs = find_lowest_abs(nums);

		// these 2 pointers "grow" from the lowest absolute value
		// 0...lowest_abs-1
		int neg_index = lowest_abs - 1;
		// lowest_abs...n-1
		int pos_index = lowest_abs;

/*
		-4 - 1 0 3 10
		pos_index: 2 -> 0
		neg_index : 1 -> - 1

		pos_index: 3 -> 3



*/

		int i = 0;
		vector<int> out(n, 0);
		while(neg_index >= 0 && pos_index < n) {
			int left_val = nums[neg_index];
			int right_val = nums[pos_index];


			if(right_val + left_val <= 0) {
				// we add the square of right_val
				int square = right_val * right_val;
				out[i++] = square;
				while(++pos_index < n && nums[pos_index] == right_val)
					out[i++] = square;
			}
			else {
				// we add the square of left_val
				int square = left_val * left_val;
				out[i++] = square;
				while(--neg_index >= 0 && nums[neg_index] == left_val)
					out[i++] = square;
			}
		}
		while(pos_index < n) {
			out[i++] = nums[pos_index] * nums[pos_index];
			++pos_index;
		}
		while(neg_index >= 0) {
			out[i++] = nums[neg_index] * nums[neg_index];
			--neg_index;
		}
		return out;


// for(int i = 0; i < n;) {
// 	int val = nums[i];
// 	int square = val * val;
// 	nums[i++] = square;
// 	while(i < n && nums[i] == val)
// 		nums[i++] = square;
// }
// sort(nums.begin(), nums.end());
// return nums;

	}
};
// @lc code=end

