# Write your MySQL query statement below
select 
s.user_id,
ifnull(round(sum(case when c.action="confirmed" then 1 else 0 end)/count(c.action),2),0) as confirmation_rate
from signups s
left join confirmations c
on c.user_id=s.user_id
group by s.user_id