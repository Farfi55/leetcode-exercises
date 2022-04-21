--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT firstName, lastName, city, state
FROM Person, Address
WHERE Person.personId = Address.personId
UNION
SELECT firstName, lastName, NULL, NULL 
FROM Person
WHERE Person.personId NOT IN (
    SELECT personId
    FROM Address   
)
-- @lc code=end

