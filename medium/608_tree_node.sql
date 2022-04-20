--
-- @lc app=leetcode id=608 lang=mysql
--
-- [608] Tree Node
--


-- @lc code=start
-- Write your MySQL query statement below

SELECT id,
IF (p_id IS NULL, "Root", 
    IF(id IN (
        SELECT p_id
        FROM Tree 
    ), "Inner", "Leaf")) AS type
FROM Tree
ORDER BY id
-- @lc code=end

