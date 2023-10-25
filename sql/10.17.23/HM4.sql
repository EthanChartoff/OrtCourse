-- HM4

/* P1 
select * from customers where Country = (select Country from customers where CustomerID='ALFKI') and CustomerID <> 'ALFKI'
*/

/* P2 
select * from products where UnitPrice = (select min(UnitPrice) from products)
*/

/* P3 
select * from products where UnitPrice > (select avg(UnitPrice) from products)
*/

/* P4 
select * from products where UnitsInStock < (select avg(UnitsInStock) from products)
*/

/* P5 
select * from employees where Salary > (select avg(Salary) from employees where DepartmentID = 2)
*/

/* P6 
select * from employees where Salary > (select Salary from employees where EmployeeID = 2) 
and DepartmentID = (select DepartmentID from employees where LastName='Davolio')
*/

/* P7 
select * from employees where Salary = any (select Salary from employees where DepartmentID = 2)
*/

/* P8 
select * from employees where Salary = any (select Salary from employees where DepartmentID = 2) and DepartmentID <> 2
*/

/* P9 
select * from employees where Salary > any (select Salary from employees where DepartmentID = 2)
*/

/* P10 
select * from employees where Salary = any (select Salary from employees where DepartmentID = 2)
*/

/* P11 
select * from employees where Salary > all (select Salary from employees where DepartmentID = 2)
*/

/* P12 
select * from employees where Salary > all (select Salary from employees where DepartmentID = 5)
*/

/* P13 
select * from products where ProductID = any (select ProductID from orderdetails where Quantity = 10)	
*/