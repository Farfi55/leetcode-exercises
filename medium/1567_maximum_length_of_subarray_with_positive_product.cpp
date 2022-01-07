/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int n = nums.size();

		int max_len = 0;
		int start = 0;
		int first_neg = -1;
		int last_neg = 0;
		int neg_counter = 0;

		int curr_len = 0;
		for(int i = 0; i < n; i++) {
			int val = nums[i];
			if(val == 0) {
				if(neg_counter % 2 == 1) {
					max_len = max(last_neg - start,
						max(i - 1 - first_neg, max_len));
				}
				else max_len = max(i - start, max_len);

				first_neg = -1;
				last_neg = -1;
				neg_counter = 0;
				curr_len = 0;
				start = i + 1;
				continue;
			}

			if(val < 0) {
				neg_counter++;
				last_neg = i;
				if(first_neg == -1)
					first_neg = i;

			}

			if(neg_counter % 2 == 0) {
				curr_len = (i + 1) - start;
				max_len = max(curr_len, max_len);

			}

		}
		if(neg_counter % 2 == 1) {
			max_len = max(last_neg - start, max_len);
			max_len = max(n - 1 - first_neg, max_len);
		}
		else max_len = max(n - start, max_len);

		return max_len;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> nums{ -1, -2, -3, 0, 1 };
	cout << Solution().getMaxLen(nums);
	return 0;
}
