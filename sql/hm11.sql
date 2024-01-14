#===----------------------
#	SQL PROCEDURES
# 	author: ethan raphael chartoff
#===----------------------

drop procedure if exists getUserFromCountry;
drop procedure if exists getEmployeeInfo;
drop procedure if exists getOrdersForEmployees;
drop procedure if exists insertOrder;
drop procedure if exists updateProductPrice;
drop procedure if exists getHighSalaryEmployees;

DELIMITER $$

create procedure getUserFromCountry(in user_country varchar(15))
begin
	select Country 
    from customers 
    where Country = user_country
    
    union all
    
    select Country 
    from employees
    where Country = user_country;
end $$

create procedure getEmployeeInfo(
	in id int,
    out e_name varchar(31),
    out e_department int,
    out e_salary int
)
begin 
	select FirstName, DepartmentID, Salary
    into e_name, e_department, e_salary
    from employees
    where EmployeeID = id;
    
    select e_name as name, e_department department, e_salary salary;
end $$

create procedure getOrdersForEmployees(
	in first_id int,
    in last_id int,
    in d_year int
)
begin
	select e.FirstName, count(*)
    from employees e join orders o
    on e.EmployeeID = o.EmployeeID
    where e.EmployeeID between first_id and last_id
    and year(o.orderDate) = d_year
    group by e.FirstName;
end $$

create procedure insertOrder(
	in c_id varchar(5),
    in e_id int,
    in order_date datetime,
    in req_date datetime
)
begin
	if 
		not exists(
			select * 
			from customers 
			where CustomerID = c_id
		)
		or not exists(
			select *
			from employees 
			where EmployeeID = e_id
		)
		or datediff(order_date, req_date) < 24
	then 
		signal sqlstate '45000' set message_text = 'params are inocorrect';
	end if;
    
    insert into orders( 
			customerID,
            employeeID,
            orderDate,
            requiredDate
		) value (
			c_id,
            e_id,
            order_date,
            req_date
        );
end $$

create procedure updateProductPrice(
	in id int,
    in new_price decimal(19, 4)
) 
begin
	update products
    set price = new_price
    where productID = id;
end $$

create procedure getHighSalaryEmployees(in min decimal)
begin 
	select * 
    from employees 
    where salary > min;
end $$

DELIMITER ;

