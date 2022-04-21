--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
-- Write your MySQL query statement below

-- LEFT JOIN will ensure that all rows of the Person table are included in the answer
-- regardless of whether the corrisponfing right table has or not any value

SELECT firstName, lastName, city, state
FROM Person
LEFT JOIN Address 
ON Person.personId = Address.personId

-- @lc code=end

