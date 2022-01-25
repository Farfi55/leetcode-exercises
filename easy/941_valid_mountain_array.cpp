/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
	bool validMountainArray(vector<int>& arr) {
		const int n = arr.size();
		if(n < 3) return false;

		int i = 0;
		while(i + 2 < n && arr[i] < arr[i + 1])
			i++;

		if(i > 0)
			while(i + 1 < n && arr[i] > arr[i + 1])
				i++;

		return i == n - 1;
	}
};
// @lc code=end

