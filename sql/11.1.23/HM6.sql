-- HM6, JOIN
-- author: Ethan Rapahel Chartoff

-- Q1
-- SELECT ProductName, CompanyName FROM products, suppliers;

-- Q2
-- SELECT suppliers.SupplierID, products.ProductID, products.ProductName, suppliers.CompanyName FROM products, suppliers WHERE suppliers.SupplierID = 1;

-- Q3
-- SELECT suppliers.CompanyName, products.ProductName, categories.CategoryName FROM suppliers, products, categories WHERE products.CategoryID = categories.CategoryID;

-- Q4
-- SELECT orders.OrderID, orders.CustomerID, concat(employees.firstName, " ",employees.lastName), orders.OrderDate FROM orders, employees WHERE (orders.EmployeeID = employees.EmployeeID) AND (orders.OrderDate > "1994.08.01" AND orders.OrderDate < "1994.08.10");

-- Q5
-- SELECT concat(employees.firstName, " ",employees.lastName) EmployeeName, count(orders.EmployeeID) FROM employees, orders WHERE employees.EmployeeID = orders.EmployeeID GROUP BY EmployeeName;

-- Q6
-- SELECT products.ProductName, count(orderdetails.ProductID) FROM products, orderdetails WHERE products.ProductID = orderdetails.ProductID GROUP BY products.ProductName;

-- Q7
-- SELECT suppliers.CompanyName, avg(products.UnitPrice) FROM suppliers, products WHERE suppliers.SupplierID = products.SupplierID GROUP BY suppliers.CompanyName;

-- Q8 
-- SELECT suppliers.CompanyName, max(products.UnitPrice) FROM suppliers, products WHERE suppliers.SupplierID = products.SupplierID GROUP BY suppliers.CompanyName;

-- Q9
-- SELECT customers.CustomerID, customers.CompanyName FROM customers WHERE customers.CustomerID = any(SELECT orders.CustomerID from orders);

-- Q10
-- SELECT products.ProductName, suppliers.CompanyName, suppliers.SupplierID FROM products LEFT JOIN suppliers ON products.ProductID = suppliers.SupplierID;

-- Q11
-- SELECT customers.CustomerID, customers.CompanyName, count(orders.OrderID) FROM customers LEFT JOIN orders ON customers.CustomerID = orders.CustomerID group by CustomerID;

-- Q12
-- SELECT suppliers.CompanyName, products.ProductName, categories.CategoryName FROM suppliers LEFT JOIN products ON suppliers.SupplierID = products.SupplierID LEFT JOIN categories ON products.CategoryID = categories.CategoryID;

-- Q13
-- SELECT concat(employees.firstName, ' ', employees.lastName), concat(manager.firstName, ' ', manager.lastName) FROM employees, employees manager WHERE employees.managerID = manager.EmployeeID;