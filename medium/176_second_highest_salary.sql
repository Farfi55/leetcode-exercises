--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary != (
    SELECT MAX(salary) AS SecondHighestSalary
    FROM Employee
)
-- @lc code=end

