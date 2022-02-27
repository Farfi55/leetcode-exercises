#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
	double average(vector<int>& salary) {
		int n = salary.size();
		int min_sal = salary[0];
		int max_sal = salary[0];
		double sum = 0;

		for(int x : salary) {
			sum += x;
			min_sal = min(min_sal, x);
			max_sal = max(max_sal, x);
		}

		return (sum - min_sal - max_sal) / (n - 2);

	}
};
// @lc code=end

