# Write your MySQL query statement below
select eu.unique_id,e.name
from employees as e
left join EmployeeUNI as eu
on e.id=eu.id