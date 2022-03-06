/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
class Solution {
public:
    string interpret(string command) {
        int n = command.length();
        string out = "";

        for(int i = 0; i < n; i++) {

            if(command[i] == 'G')
                out += 'G';
            else if(command[i] == '(') {
                if(command[i + 1] == ')') {
                    out += 'o';
                    i += 1;
                }
                else {
                    out += "al";
                    i += 3;
                }
            }

        }
        return out;
    }

};
// @lc code=end

