# Write your MySQL query statement below
select FirstName,LastName,City,State from Person  Left Join Address using (personId);

# select p.FirstName, p.LastName, a.City, a. State
# from Person p, Address a 
# where p.PersonId = a.PersonId;