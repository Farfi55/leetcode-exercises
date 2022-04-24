--
-- @lc app=leetcode id=586 lang=mysql
--
-- [586] Customer Placing the Largest Number of Orders
--



-- @lc code=start
-- Write your MySQL query statement below

SELECT customer_number
FROM Orders O
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1

/*
FOR FOLLOW UP QUESTION 

SELECT customer_number FROM Orders 
GROUP BY customer_number
HAVING COUNT(customer_number) >= ALL 
(SELECT COUNT(customer_number) FROM Orders GROUP BY customer_number)
*/


-- @lc code=end

