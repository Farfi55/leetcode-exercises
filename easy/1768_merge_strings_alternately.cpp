/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        int n_min = min(n1, n2);

        string out = "";
        for(int i = 0; i < n_min; i++) {
            out += word1[i];
            out += word2[i];
        }
        if(n1 > n_min)
            out += word1.substr(n_min);
        else if(n2 > n_min)
            out += word2.substr(n_min);

        return out;

    }
};
// @lc code=end

