# Write your MySQL query statement below
SELECT x, y, z,
    CASE
        WHEN GREATEST(x,y,z) < x + y + z - GREATEST(x,y,z)
        THEN 'Yes'
        ELSE 'No'
    END as triangle
FROM
    triangle