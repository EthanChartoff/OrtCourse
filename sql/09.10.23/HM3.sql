/* HM3, Funcs */

/* Problem 1 
select min(lastName) from employees;
*/

/* Problem 2 
select sum(Quantity*UnitPrice*(1-Discount)) from orderdetails where OrderId=10248;
*/

/* Problem 3 
select OrderID from orderdetails where UnitPrice=(select min(UnitPrice) from orderdetails);
*/

/* Problem 4 
select avg(UnitPrice) from orderdetails;
*/

/* Problem 5 
select avg(QuantityPerUnit) from products;
*/

/* Problem 6 
select count(*) from customers where (City='London' or City='Berlin');
*/

/* Problem 7 
select min(Salary) as 'smallest salary', max(Salary) as 'largest salary', avg(Salary) as 'average salary' from employees;
*/