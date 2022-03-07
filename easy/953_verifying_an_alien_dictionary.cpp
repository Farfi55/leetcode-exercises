/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int prio[26] = { 0 }; // priority list
        for(int i = 0; i < order.length(); i++)
            prio[order[i] - 'a'] = i;

        for(int i = 0; i < words.size() - 1; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                if(words[i + 1].length() == j)
                    return false;
                else if(words[i][j] == words[i + 1][j])
                    continue;
                else if(prio[words[i][j] - 'a'] > prio[words[i + 1][j] - 'a'])
                    return false;
                else break;
            }
        }
        return true;
    }
};
// @lc code=end

