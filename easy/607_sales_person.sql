--
-- @lc app=leetcode id=607 lang=mysql
--
-- [607] Sales Person
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT sales_id
    FROM Orders O, Company C
    WHERE C.name = "RED" AND O.com_id = C.com_id
)

-- @lc code=end

