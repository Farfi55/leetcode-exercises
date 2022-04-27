/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
#include<string>
#include<vector>
#include <regex>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t lenght = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(lenght != 0)
                    return lenght;
            }
            else lenght++;
        }
        return lenght;
    }
};
// @lc code=end

