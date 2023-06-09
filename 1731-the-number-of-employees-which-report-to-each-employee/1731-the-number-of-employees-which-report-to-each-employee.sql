# Write your MySQL query statement below
SELECT e.employee_id, e.name, r.reports_count, ROUND(r.average_age) AS average_age
FROM Employees e
JOIN (
  SELECT reports_to, COUNT(*) AS reports_count, AVG(age) AS average_age
    
  FROM Employees
  WHERE reports_to IS NOT NULL
  GROUP BY reports_to
) r ON e.employee_id = r.reports_to
ORDER BY e.employee_id;