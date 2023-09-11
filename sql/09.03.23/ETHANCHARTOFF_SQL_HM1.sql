/*
	HM 1 SELECT 
*/

/* problem 1
select City from customers;
*/

/* problem 2
select distinct City from customers;
*/

/* problem 3
select distinct CompanyName from suppliers limit 10;
*/

/* problem 4
select EmployeeID, FirstName, LastName from employees;
*/

/* problem 5
select ProductName, UnitPrice, UnitPrice*0.9 as PriceAfterSale from products;
*/

/* problem 6
select ProductName, UnitPrice, UnitPrice*0.9 as NewUnitPrice from products;
*/

/* problem 7 
select distinct CustomerID from customers;
*/

/* problem 8 
select ProductName, QuantityPerUnit from products order by QuantityPerUnit desc;
*/

/* problem 9 
select Country from customers order by Country asc;
*/

/* problem 10 
select Country, City, BirthDate, LastName, FirstName from employees order by BirthDate;
*/

/* problem 11 
select concat(Country, " - ",City) as address, BirthDate, LastName, FirstName from employees order by BirthDate;
*/

/* problem 12 
select UnitPrice from products order by UnitPrice desc limit 10;
*/

/* problem 13 
select UnitPrice from products order by UnitPrice asc limit 10;
*/

/* problem 14 
select FirstName, LastName, Salary from employees order by Salary limit 1 offset 2;
*/