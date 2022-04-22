--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- @lc code=start
-- Write your MySQL query statement below
-- id
-- recordDate
-- temperature
SELECT A.id
FROM Weather A, Weather B
WHERE DATEDIFF(A.recordDate, B.recordDate) = 1 
    AND A.temperature > B.temperature

-- @lc code=end

