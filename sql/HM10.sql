-- HM10, insert
-- author: Ethan Raphael Chartoff

-- Q1
insert into employees(LastName, FirstName, Title, BirthDate, Address, City, Region, PostalCode, Country, HomePhone, Salary, DepartmentID)
	values("goodman", "saul", "lawyer", "1964-06-09", "sal road 2234", "albaquerqie", "NM", "72087", "USA", "(71)555-2122", 10000, 2);
select * from employees;

-- Q2
insert into orders(CustomerID, EmployeeID, OrderDate, RequiredDate)
	value("ALFKI", 10, curdate(), adddate(curdate(), interval 3 day));
select * from orders;

-- Q3
insert into orderdetails(OrderID, ProductID, UnitPrice, Quantity, Discount) 
	select max(o.OrderID), 
    (select p.ProductID from products p where p.ProductName = "Chai"),
    (select p.UnitPrice from products p where p.ProductName = "Chai"),
    (select p.UnitsInStock from products p where p.ProductName = "Chai"),
    0.1
		from orders o where o.CustomerID = "ALFKI";
select * from orderdetails;

-- Q4
delete from categories c 
	where not exists(select 1 
		from products p 
        where p.CategoryID = c.CategoryID)
	limit 1;

-- Q5
delete from orders o 
	where o.CustomerID = 
		(select c.CustomerID from customers c 
			where c.City = 'Berlin' 
            and not exists (select 1
				from orderdetails od 
					where od.OrderID = o.OrderID))
limit 1000; -- limit skip safe mode 

-- Q6
update products 
set products.UnitPrice = 30 
	where products.ProductName = "coffe";

-- Q7
update employees
set employees.Region = "Rg" 
	where employees.Region is null
limit 1000;

-- Q8
update products 
set products.UnitPrice = products.UnitPrice * 1.1
	where products.SupplierID = 1;

-- Q9
update employees
set employees.Salary = employees.Salary * 1.1
	where employees.EmployeeID = any 
		(select o.EmployeeID from orders o where year(o.orderDate) group by o.EmployeeID having count(*) > 2)
limit 1000;
