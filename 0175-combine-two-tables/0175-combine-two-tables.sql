# Write your MySQL query statement below
select  firstName,lastname,city,state from Person as p1
left Join Address  as A1
on P1.personId=A1.personid
