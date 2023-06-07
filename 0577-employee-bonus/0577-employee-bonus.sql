# Write your MySQL query statement below
SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN (
    SELECT empId, SUM(bonus) as bonus 
    FROM Bonus
    GROUP BY empId
) b ON e.empId = b.empId WHERE b.bonus IS NULL OR b.bonus < 1000;