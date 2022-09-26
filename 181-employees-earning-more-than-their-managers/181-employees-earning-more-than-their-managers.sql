# Write your MySQL query statement below
select E.name as Employee from Employee E,Employee M where E.managerId is not NULL and E.managerID=M.id and E.salary>M.salary;