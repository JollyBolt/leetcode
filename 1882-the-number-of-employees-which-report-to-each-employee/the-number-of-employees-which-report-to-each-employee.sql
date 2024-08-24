# Write your MySQL query statement below
with my_cte as (
    select reports_to,count(employee_id) as reports_count,round(avg(age),0) as average_age
    from employees
    where reports_to is not null
    group by reports_to
)

select e.employee_id,e.name,c.reports_count,c.average_age
from my_cte as c
inner join employees as e
on c.reports_to = e.employee_id
order by e.employee_id
