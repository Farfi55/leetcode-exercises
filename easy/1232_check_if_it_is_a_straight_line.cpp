#include <vector>
#include <cmath>
#include <iostream>

using std::vector;
/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */



// @lc code=start
#define EPS 2e-8

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double base_dir_x = coordinates[1][0] - coordinates[0][0];
        double base_dir_y = coordinates[1][1] - coordinates[0][1];

        double magnitude = sqrt(base_dir_x * base_dir_x + base_dir_y * base_dir_y);
        base_dir_x /= magnitude;
        base_dir_y /= magnitude;


        for(int i = 2; i < coordinates.size(); i++) {
            double dir_x = coordinates[i][0] - coordinates[0][0];
            double dir_y = coordinates[i][1] - coordinates[0][1];
            double magnitude = sqrt(dir_x * dir_x + dir_y * dir_y);
            dir_x /= magnitude;
            dir_y /= magnitude;

            if((abs(dir_x - base_dir_x) > EPS || abs(dir_y - base_dir_y) > EPS) &&
                (abs(dir_x + base_dir_x) > EPS || abs(dir_y + base_dir_y) > EPS))

                return false;
        }

        return true;
    }
};
// @lc code=end


int main(int argc, char const* argv[])
{
    vector<vector<int>> coords = { {0, 0}, { 0,1 }, { 0,-1 } };
    std::cout << Solution().checkStraightLine(coords);
    return 0;
}

