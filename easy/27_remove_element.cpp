/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int k = nums.size();
		for(int i = 0; i < k; i++)
			while(nums[i] == val && k > i)
				if(--k > i)
					nums[i] = nums[k];
		return k;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums{ 0,1,2,2,3,0,4,2 };
	int n = sol.removeElement(nums, 2);

	for(int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}

	return 0;
}

