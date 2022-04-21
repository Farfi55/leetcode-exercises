--
-- @lc app=leetcode id=1581 lang=mysql
--
-- [1581] Customer Who Visited but Did Not Make Any Transactions
--


-- @lc code=start
-- Write your MySQL query statement below

SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits V
WHERE visit_id NOT IN (
    SELECT visit_id
    FROM Transactions
)
GROUP BY customer_id

-- @lc code=end

