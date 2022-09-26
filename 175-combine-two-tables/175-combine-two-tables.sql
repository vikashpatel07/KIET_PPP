# Write your MySQL query statement below
SELECT Firstname,Lastname, City ,State from Person Left Join Address ON person.personId=Address.personId;