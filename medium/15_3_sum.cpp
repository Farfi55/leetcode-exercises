/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> out;
		sort(nums.begin(), nums.end());
		const int n = nums.size();
		for(int i = 0; i < n; i++) {
			// if the first element of the triplet is > 0, 
			// we won't find any that summed will give 0 anymore
			if(nums[i] > 0) break;

			int left = i + 1;
			int right = n - 1;

			while(left < right) {

				int sum = nums[i] + nums[left] + nums[right];
				if(sum < 0) left++;
				else if(sum > 0) right--;
				else {
					vector<int> triplet{ nums[i], nums[left], nums[right] };
					out.push_back(triplet);

					// getting the next value for left and right
					while(left + 1 < right && nums[left] == triplet[1]) ++left;
					while(left < right && nums[right] == triplet[2]) --right;
				}
			}
			// we skip to the next value for i
			while(i + 1 < n && nums[i] == nums[i + 1]) i++;

		}
		return out;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> vec{ -1,0,1,2,-1,-4 };
	Solution sol;
	auto out = sol.threeSum(vec);

	for(auto& triplet : out) {
		cout << '[' << triplet[0] << " " << triplet[1] << " " << triplet[2] << "]\n";
	}
	return 0;
}
