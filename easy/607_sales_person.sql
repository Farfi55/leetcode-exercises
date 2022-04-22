--
-- @lc app=leetcode id=607 lang=mysql
--
-- [607] Sales Person
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT S.name
FROM Orders O 
JOIN Company C
ON O.com_id = C.com_id AND C.name = "RED"
RIGHT JOIN SalesPerson S
ON S.sales_id = O.sales_id
WHERE O.sales_id IS NULL
-- @lc code=end

