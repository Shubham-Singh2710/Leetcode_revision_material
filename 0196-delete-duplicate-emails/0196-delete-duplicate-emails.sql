# Write your MySQL query statement below
delete  p1 from Person as p1
join Person as P2
ON p1.email=p2.email
And p1.id>p2.id