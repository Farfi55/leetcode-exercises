/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> out;
		sort(nums.begin(), nums.end());
		const int n = nums.size();

		for(int i = 0; i < n - 3; i++) {
			for(int j = i + 1; j < n - 2; j++) {
				// if the first element of the triplet is > 0, 
				// we won't find any that summed will give 0 anymore


				int front = j + 1;
				int back = n - 1;

				int sum_target = target - nums[i] - nums[j];

				while(front < back) {
					int two_sum = nums[front] + nums[back];

					if(two_sum < sum_target) front++;
					else if(two_sum > sum_target) back--;
					else {
						vector<int> quadrutuplet{ nums[i], nums[j], nums[front], nums[back] };
						out.push_back(quadrutuplet);

						// processing front and back duplicates
						while(front + 1 < back && nums[front] == quadrutuplet[2]) ++front;
						while(front < back && nums[back] == quadrutuplet[3]) --back;
					}
				}
				// processing j duplicates
				while(j + 3 < n && nums[j] == nums[j + 1]) j++;

			}
			// processing j duplicates
			while(i + 4 < n && nums[i] == nums[i + 1]) i++;
		}
		return out;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution sol;
	vector<int> nums = { 1,-2,-5,-4,-3,3,3,5 };
	int target = -11;

	auto out = sol.fourSum(nums, target);

	for(auto& quadrutuplet : out) {
		cout << '[' << quadrutuplet[0] << ' '
			<< quadrutuplet[1] << ' '
			<< quadrutuplet[2] << ' '
			<< quadrutuplet[3] << "]\n";
	}
	return 0;
}
