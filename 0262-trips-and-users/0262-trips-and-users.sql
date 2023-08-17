# Write your MySQL query statement below
SELECT
    t.request_at AS day,
    ROUND(SUM(CASE WHEN t.status LIKE 'cancelled%' THEN 1 ELSE 0 END) / COUNT(*), 2) AS "Cancellation Rate"
    
FROM
    trips t
LEFT JOIN
    users u ON u.users_id = t.client_id AND u.role = 'client' AND u.banned = 'No'
LEFT JOIN
    users u1 ON u1.users_id = t.driver_id AND u1.role = 'driver' AND u1.banned = 'No'
WHERE
    (u.banned IS NOT NULL and u1.banned IS NOT NULL)
    AND t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY
    t.request_at;
