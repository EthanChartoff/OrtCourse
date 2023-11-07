-- HM7, subqueries
-- author: Ethan Raphael Chartoff

-- Q1
-- select e.FirstName, e.Salary, (select avg(employees.Salary) from employees) avgSalary from employees e;

-- Q2
-- select e.FirstName, e.Salary from employees e where e.Salary > (select avg(employees.Salary) from employees where employees.DepartmentID = 2);

-- Q3
-- select e.FirstName, e.Salary from employees e where e.Salary > (select avg(e1.Salary) from employees e1 where e1.DepartmentID = e.DepartmentID);

-- Q4
-- select o.CustomerID from orders o where (select count(*) from orderdetails where o.OrderID = orderdetails.OrderID) > 3;

-- Q5
-- select ProductName, UnitPrice, CategoryID from products p where UnitPrice in (select max(UnitPrice) from products p1 where p1.CategoryID = p.CategoryID); 

-- Q6
-- select s.ContactName, p.ProductName, p.UnitPrice from suppliers s, products p where p.UnitPrice in (select max(p1.UnitPrice) from products p1, suppliers s1 where s1.ContactName = s.ContactName);

-- Q7
-- select c.CompanyName, (select count(*) from orders o where o.CustomerID = c.CustomerID) from customers c;

-- Q8
-- select e.FirstName from employees e where (select count(*) from orders o where o.EmployeeID = e.EmployeeID) > 1;

-- Q9
-- select e.FirstName from employees e where (select count(distinct o.CustomerID) from orders o where o.EmployeeID = e.EmployeeID) > 1;

-- Q10
-- select distinct od.OrderID, (select count(*) from orderdetails od1 where od.OrderID = od1.OrderID) from orderdetails od;

-- Q11
-- select c.CustomerID, (select count(*) from orders o where o.CustomerID = c.CustomerID) from customers c;

-- Q12
-- select c.CustomerID, c.Country from customers c where c.CustomerID in (select o.CustomerID from orders o, orderdetails od where o.)

