# Write your MySQL query statement below


# select E.name as Employee from Employee E,Employee M where E.managerId is not NULL and E.managerID=M.id and E.salary>M.salary;

select E.name as Employee from Employee as E JOIN Employee as M on E.managerId=M.Id and E.Salary>M.Salary;