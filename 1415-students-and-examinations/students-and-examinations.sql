# Write your MySQL query statement below
with my_cte as (
select * 
from students st
cross join subjects sb
order by st.student_id,sb.subject_name
),
my_cte2 as (
select *,count(student_id) as attended_exams
from examinations
group by subject_name,student_id
)

select c1.*,ifnull(c2.attended_exams,0) as attended_exams
from my_cte as c1
left join my_cte2 as c2
on c1.student_id=c2.student_id and c1.subject_name=c2.subject_name
order by c1.student_id,c1.subject_name
