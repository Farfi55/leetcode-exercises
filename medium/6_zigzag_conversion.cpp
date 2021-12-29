/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        const unsigned n = s.size();

        if(numRows == 1 || n <= numRows) return s;

        vector<string> rows(numRows, "");

        int row_index = 0;
        int increment = 1;

        for(char& c : s) {
            rows[row_index] += c;
            row_index += increment;
            if(row_index == 0 || row_index == numRows - 1)
                increment = -increment;
        }



        for(int i = 1; i < numRows; i++)
            rows[0] += rows[i];
        return rows[0];

                // std::string new_s;

                // // first row
                // for(int i = 0; i < n; i += ((numRows - 1) * 2))
                //     new_s += s[i];

                // // middle rows
                // for(int row = 1; row < numRows - 1; row++) {
                //     for(int i = row; i < n;) {
                //         new_s += s[i];

                //         i += (numRows - (row + 1)) * 2;
                //         if(i >= n) break;
                //         new_s += s[i];

                //         i += row * 2;
                //     }
                // }

                // // last row
                // for(int i = numRows - 1; i < n; i += ((numRows - 1) * 2))
                //     new_s += s[i];

                // return new_s;
    }

};
// @lc code=end

