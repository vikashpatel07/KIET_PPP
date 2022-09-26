# Write your MySQL query statement below
select  c.name AS Customers from Customers as C Left Join Orders as O ON  C.id=O.customerId  where  O.customerId IS NULL;