-- HM9, union
-- author: Ethan Raphael Chartoff

-- Q1
select c.city from customers c
union all 
select e.city from employees e;

-- Q2
select c.city from customers c
union all 
select e.city from employees e
order by city;

-- Q3
select c.city from customers c where c.Country = "germany"
union 
select e.city from employees e where e.Country = "germany";

-- Q4
select 'customer' as usertype, contactname, city, country
from customers
union
select 'supplier', contactname,city, country
from suppliers 
union
select 'employee', concat(firstname, " ", lastname), City, Country 
from employees;