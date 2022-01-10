#include <vector>
#include <string>
#include <iostream>
using namespace std;


/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1;
		int level = 0;
		int water = 0;

		while(l < r) {
			// lower = whichever side il smallest, 
			// then move it towards the other
			int lower = height[height[l] < height[r] ? l++ : r--];
			level = max(level, lower);
			water += level - lower;
		}
		return water;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> heights{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << Solution().trap(heights);
	return 0;
}


