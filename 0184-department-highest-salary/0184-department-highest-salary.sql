# Write your MySQL query statement below

select department.name as Department, employee.name as Employee,salary as Salary
from employee
inner join department
on employee.departmentId=department.id
where (salary,departmentId) in (
      select max(salary) as salary,departmentId
      from employee 
      group by departmentId
)