--
-- @lc app=leetcode id=1407 lang=mysql
--
-- [1407] Top Travellers
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT name, COALESCE(SUM(distance),0) AS travelled_distance
FROM Users 
LEFT JOIN Rides ON Users.id = Rides.user_id
GROUP BY Users.id
ORDER BY travelled_distance DESC, name


-- @lc code=end

