# Write your MySQL query statement below
select e.name from Employee e
join Employee m
on e.id=m.managerId
group by e.name,m.managerId
having count(e.id)>=5