# Write your MySQL query statement below
# select distinct P.email as  Email from Person AS p JOIN Person AS q ON p.email=q.email and p.id<>q.id;

select  p.email as Email from person as p GROUP BY email having count(email)>1;