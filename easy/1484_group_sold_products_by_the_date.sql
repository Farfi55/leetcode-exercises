--
-- @lc app=leetcode id=1484 lang=mysql
--
-- [1484] Group Sold Products By The Date
--



-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    sell_date, 
    COUNT(DISTINCT product) AS num_sold, 
    GROUP_CONCAT(DISTINCT product ORDER BY 1) AS products
FROM Activities AS A
GROUP BY sell_date 
ORDER BY 1
-- @lc code=end

