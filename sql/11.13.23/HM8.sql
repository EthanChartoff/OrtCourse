-- HM8, exists
-- author: Ethan Raphael Chartoff

--  Q1
select c.CustomerID from customers c where exists (select 1 from orders o where c.CustomerID = o.CustomerID and o.OrderDate > "1994-08-15");

-- Q2
select c.CustomerID from customers c where exists (select 1 from orders o where c.CustomerID = o.CustomerID);

-- Q3
select c.CustomerID from customers c where not exists (select 1 from orders o where c.CustomerID = o.CustomerID);

-- Q4a
select c.CustomerID from customers c 
	where exists (select 1 from orderdetails od, orders o where o.OrderID = od.OrderID and c.CustomerID = o.CustomerID 
		and exists (select 1 from orderdetails od where od.ProductID = 11) 
		and exists (select 1 from orderdetails where od.ProductID = 42));

-- Q4b
select c.CustomerID from customers c 
	where exists (select 1 from orders o where o.CustomerID = c.CustomerID 
		and exists (select 1 from orderdetails od where od.OrderID = o.OrderID and od.ProductID = 11) 
		and exists (select 1 from orderdetails od where od.OrderID = o.OrderID and od.ProductID = 42));

-- Q5
select c.CustomerID from customers c 
	where exists (select 1 from orders o 
		where c.CustomerID = o.CustomerID
		and not exists (select 1 from orderdetails od where o.OrderID = od.OrderID and od.ProductID = 11));

-- Q6
select o.CustomerID from orders o 
	where not exists (select 1 from orderdetails od 
		where od.OrderID = o.OrderID);

-- Q7
select o.CustomerID from orders o 
	where coalesce((select od.orderID from orderdetails od 
		where o.orderID = od.orderID and od.productID = 55), 0) > 
		coalesce((select od.orderID from orderdetails od 
			where o.orderID = od.orderID and od.productID = 42), 0);