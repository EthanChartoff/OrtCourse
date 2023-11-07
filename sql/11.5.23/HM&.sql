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
select ProductName, UnitPrice, CategoryID from products group by CategoryID having UnitPrice in (select UnitPrice from products p1 where products.ProductID = p1.ProductID);
