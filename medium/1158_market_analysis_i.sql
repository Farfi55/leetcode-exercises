--
-- @lc app=leetcode id=1158 lang=mysql
--
-- [1158] Market Analysis I
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    user_id AS buyer_id, 
    join_date, 
    COALESCE(COUNT(O.order_id),0) AS orders_in_2019 
FROM Users U
LEFT JOIN Orders O ON U.user_id = O.buyer_id AND YEAR(order_date) = '2019'
GROUP BY user_id



-- @lc code=end

