// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem605.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
	bool get(vector<int>& flowerbed, int i) {
		return (i < 0) || (i >= flowerbed.size()) || !flowerbed[i];
	}
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		for(int i = 0; i < flowerbed.size(); i++) {
			if(get(flowerbed, i - 1) && get(flowerbed, i) && get(flowerbed, i + 1)) {
				n--;
				i++;
			}
		}


		return n <= 0;
	}
};
// @lc code=end

