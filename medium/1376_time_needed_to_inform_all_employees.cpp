#include <vector>

using namespace std;
/*
*@lc app = leetcode id = 1376 lang = cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {

    int getEmployeesTime(int manager, vector<int>& informTime, vector<vector<int>>& employees) {
        int employeesTime = 0;
        for(int empl : employees[manager])
            employeesTime = max(employeesTime,
                informTime[empl] + getEmployeesTime(empl, informTime, employees));

        return employeesTime;
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> employees(n, vector<int>());

        for(int i = 0; i < n; i++)
            if(i != headID)
                employees[manager[i]].push_back(i);


        return getEmployeesTime(headID, informTime, employees) + informTime[headID];
    }
};
// @lc code=end

