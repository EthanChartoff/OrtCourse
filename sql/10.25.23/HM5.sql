/* HM5, GROUP BY, HAVING */

-- P1 
-- select OrderID, Quantity from orderdetails;

-- P2
-- select CustomerID, count(*) from orders group by CustomerID;

-- P3
-- select DepartmentID, avg(Salary) from employees group by DepartmentID;

-- P4
-- select DepartmentID, avg(Salary) from employees group by DepartmentID having DepartmentID < 3;

-- P5
-- select SupplierID, count(*) from products group by SupplierID;

-- P6
-- select SupplierID, CategoryID, count(*) from products group by SupplierID, CategoryID;

-- P7
-- select DepartmentID, avg(Salary) from employees group by DepartmentID having avg(Salary) > 10000;

-- P8 
-- select Country, count(*) from customers group by Country;

-- P9
-- select Country, count(*) from customers group by Country having Country = 'USA' or Country = 'Argentina';

-- P10
-- select Country, count(*) from customers group by Country having Country = 'USA';

-- P11
-- select Country, count(distinct City) from customers group by Country;

-- P12
-- select SupplierID, max(UnitPrice) from products group by SupplierID;

-- P13
-- select ProductName, ProductID from products where ProductID = any(select ProductID from orderdetails group by ProductID having count(*) > 1);

-- P14
-- select FirstName from employees where Salary > any(select avg(Salary) from employees group by DepartmentID);

