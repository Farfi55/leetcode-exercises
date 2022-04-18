--
-- @lc app=leetcode id=1873 lang=mysql
--
-- [1873] Calculate Special Bonus
--



-- @lc code=start
-- Write your MySQL query statement below
SELECT employee_id, salary AS bonus
FROM Employees
WHERE MOD(employee_id, 2) = 1 AND name NOT LIKE "M%"
UNION 
SELECT employee_id, 0 AS bonus
FROM Employees
WHERE MOD(employee_id, 2) = 0 OR name LIKE "M%"
ORDER BY employee_id
-- @lc code=end

