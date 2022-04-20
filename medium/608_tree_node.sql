--
-- @lc app=leetcode id=608 lang=mysql
--
-- [608] Tree Node
--


-- @lc code=start
-- Write your MySQL query statement below

SELECT id,
CASE
    WHEN p_id IS NULL THEN "Root"
    WHEN id IN ( SELECT p_id FROM Tree) THEN "Inner"
    ELSE "Leaf"
END AS type
FROM Tree
ORDER BY id
-- @lc code=end

