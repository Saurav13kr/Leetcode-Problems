# Write your MySQL query statement below
SELECT contest_id, ROUND((COUNT(user_id) / total_users) * 100, 2) AS percentage
FROM Register
JOIN (
    SELECT COUNT(DISTINCT user_id) AS total_users
    FROM Users
) AS total GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;