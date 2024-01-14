-- HM11, view
-- author: Ethan Raphael Chartoff

ALTER TABLE employees
ADD startDate date;

-- Q1
CREATE OR REPLACE VIEW employee AS
SELECT EmployeeID, firstname, birthdate, DATE_FORMAT(NOW(), '%Y')-DATE_FORMAT(birthdate, '%Y')-(DATE_FORMAT(NOW(), '00-%m-%d') < DATE_FORMAT(birthdate, '00-%m-%d'))
from employees; 

-- Q2
CREATE OR REPLACE VIEW employee_work_details AS
SELECT firstname, lastname, startDate, DATE_FORMAT(NOW(), '%Y')-DATE_FORMAT(startDate, '%Y'),
DATE_FORMAT(NOW(), '%m')-DATE_FORMAT(startDate, '%m')
from employees;


-- Q3
CREATE OR REPLACE VIEW employees_salary_date AS
SELECT firstname, startDate, DATE_ADD(startDate, INTERVAL 1 YEAR)
from employees where DATE_ADD(startDate, INTERVAL 1 YEAR) > current_date()
    and current_date() is not null; 


-- Q4
CREATE OR REPLACE VIEW customers_long_gap_ AS
SELECT * 
from customers c 
where (select max(orderDate) 
    from orders o 
    where o.customerid = c.customerid) >= DATE_ADD((select min(orderDate) 
        from orders o where 
        o.customerid = c.customerid),INTERVAL 500 DAY);