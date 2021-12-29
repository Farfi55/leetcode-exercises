/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // last index char i appared in the string, 0 = never, 1 = 1° char and so on
        int character_at[128] = { 0 };
        int max_lenght = 0;
        int current_lenght = 0;
        for(int i = 0; i < s.size(); i++) {
            const unsigned char c = s[i];
            if(character_at[c] > i - current_lenght) {
                current_lenght = i - (character_at[c] - 1);
            }
            else current_lenght++;

            character_at[c] = i + 1;

            if(current_lenght > max_lenght)
                max_lenght = current_lenght;
        }

        return max_lenght;

    }
};
// @lc code=end

