#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
    struct Point {
        int i, j, dist;
        Point(int i, int j, int dist) :
            i(i), j(j), dist(dist) {}
    };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<Point> q;
        q.emplace(entrance[0], entrance[1], 0);
        maze[entrance[0]][entrance[1]] = '+';


        while(!q.empty()) {
            int i = q.front().i;
            int j = q.front().j;
            int dist = q.front().dist;
            q.pop();

            if((i == 0 || j == 0 || i == m - 1 || j == n - 1)
                && (i != entrance[0] || j != entrance[1]))
                return dist;


            if(i + 1 < m && maze[i + 1][j] == '.') {
                q.emplace(i + 1, j, dist + 1);
                maze[i + 1][j] = '+';
            }
            if(j + 1 < n && maze[i][j + 1] == '.') {
                q.emplace(i, j + 1, dist + 1);
                maze[i][j + 1] = '+';
            }
            if(i - 1 >= 0 && maze[i - 1][j] == '.') {
                q.emplace(i - 1, j, dist + 1);
                maze[i - 1][j] = '+';
            }
            if(j - 1 >= 0 && maze[i][j - 1] == '.') {
                q.emplace(i, j - 1, dist + 1);
                maze[i][j - 1] = '+';
            }
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{

    vector<vector<char>> maze = { {'+', '+', '.', '+'}, { '.', '.', '.', '+' }, { '+', '+', '+', '.' } };
    vector<int> entrance = { 1, 2 };

    Solution().nearestExit(maze, entrance);
    return 0;
}
