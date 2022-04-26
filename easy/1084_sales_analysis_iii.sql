--
-- @lc app=leetcode id=1084 lang=mysql
--
-- [1084] Sales Analysis III
--


-- @lc code=start
-- Write your MySQL query statement below

SELECT product_id, product_name
FROM Product
WHERE product_id NOT IN (
    SELECT product_id
    FROM Sales
    WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31'
)

-- @lc code=end

