/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include <string>
#include <vector>

using namespace std;


// @lc code=start
class Solution {
public:
	string multiply(string a, string b) {
		if(a == "0" || b == "0")
			return "0";

		const int m = a.size() - 1;
		const int n = b.size() - 1;
		int carry = 0;

		string product;
		product.reserve(m + n + 2);

		for(int i = 0; i <= m + n || carry; ++i) {
			for(int j = max(0, i - n); j <= min(i, m); ++j) {
				int a_digit = (a[m - j] - '0');
				int b_digit = (b[n - i + j] - '0');
				carry += a_digit * b_digit;
			}
			product = char(carry % 10 + '0') + product;
			carry /= 10;
		}
		return product;
	}
};
// @lc code=end

