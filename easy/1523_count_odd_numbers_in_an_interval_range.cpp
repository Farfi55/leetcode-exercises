/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */






// @lc code=start
class Solution {
public:
	int countOdds(int low, int high) {
		// high : 7 -> 6 
		// low  : 3 -> 2
		bool high_odd = high & 1;
		bool low_odd = low & 1;


		int count = ((high - high_odd) - (low + low_odd)) / 2;
		count += high_odd + low_odd;
		return count;
	}
};
// @lc code=end

