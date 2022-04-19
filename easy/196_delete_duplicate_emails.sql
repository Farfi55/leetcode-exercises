--
-- @lc app=leetcode id=196 lang=mysql
--
-- [196] Delete Duplicate Emails
--

-- @lc code=start
-- Please write a DELETE statement and DO NOT write a SELECT statement.
-- Write your MySQL query statement below

-- DELETE p1
-- FROM Person p1, Person p2
-- WHERE p1.email = p2.email AND p1.id > p2.id


DELETE FROM Person
WHERE id NOT IN (
    SELECT p.id FROM (
        SELECT MIN(id) AS id
        FROM Person
        GROUP BY email
    )p
)

-- @lc code=end

