/* HM 2, Conditions */

/* Problem 1
select * from customers where Country='Germany' and (City='Berlin' or City='London'); -- output: 1
select * from customers where Country='Germany' and City='Berlin' or City='London'; -- output : 7

-- The first condition demands a rows Country to be Germany AND the cities Berlin OR London, 
-- so you either live in Germany, Berlin or Germany, London (which is impossible), so YOU HAVE TO LIVE IN GERMANY.

-- alternitivly the second condition demands a rows Country to be Germany And the City be Berlin, Or ONLY the city being London. 
-- so you either live in Germany, Berlin or London.
*/

/* Problem 2 
select * from customers where not (Country='Germany' or Country='UK');
*/

/* Problem 3 
select ProductID, ProductName from products where UnitPrice >= 10 and UnitPrice <= 20;	
*/

/* Problem 4 
select ProductID, ProductName from products where not (UnitPrice >= 10 and UnitPrice <= 20);	
*/

/* Problem 5
select ProductID, ProductName from products where UnitPrice >= 10 and UnitPrice <= 20 and CategoryID > 3;	
*/

/* Problem 6 
select ProductID, ProductName from products where UnitsInStock > 50;
*/

/* Problem 7
select ProductID, ProductName from products where SupplierID=2;
*/

/* Problem 8
select SupplierID, CompanyName, City from suppliers where (City='Tokyo' or City='London');
*/

/* Problem 9
select * from customers where binary (CompanyName like 'A%' or CompanyName like '%e');
*/

/* Problem 10 
select ProductID, ProductName from products where UnitPrice > 30;
*/

/* Problem 11 
select ProductID, ProductName from products where (UnitsInStock < 10 and UnitPrice > 30);
*/

/* Problem 12 
select * from customers where (CompanyName like 'G%' and Country='Spain');
*/

/* Problem 13 
select * from employees where BirthDate > '1950-01-01';
*/