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
	int trap(vector<int>& heights) {
		int n = heights.size();
		vector<int> height_left(n);
		vector<int> height_right(n);

		int rain = 0;


		height_left[0] = heights[0];
		height_right[n - 1] = heights[n - 1];
		for(int i = 1; i < n; i++) {
			height_left[i] = max(height_left[i - 1], heights[i]);
			height_right[n - 1 - i] = max(height_right[n - i], heights[n - 1 - i]);
		}

		for(int i = 0; i < n; i++) {
			int amount = min(height_left[i], height_right[i]) - heights[i];
			if(amount > 0) rain += amount;
		}

		return rain;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	vector<int> heights{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << Solution().trap(heights);
	return 0;
}


