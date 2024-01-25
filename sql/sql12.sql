#===----------------------
#	SQL dynamic sql and loops
# 	author: ethan raphael chartoff
#===----------------------

drop procedure if exists missingDatesOrders;
drop procedure if exists calculateVacationDays;
drop procedure if exists calculateVacationDays2;
drop procedure if exists dynamicLoopExample;

DELIMITER $$

CREATE PROCEDURE missingDatesOrders(
	in startDate date,
	in endDate date
)
BEGIN
	declare posDate date;
    set posDate = startDate;
    create temporary table if not exists dateRange(dateInPeriod date);
    
    while posDate < endDate do
		insert into dateRange
        values(posDate);
        
        set posDate = date_add(posDate, INTERVAL 1 DAY);
    end while;
    
    select dateInPeriod
    from dateRange left join orders
    on dateInPeriod = OrderDate
    where orderID is null;
END $$

CREATE PROCEDURE calculateVacationDays()
BEGIN
	declare pVacationDays int;
    declare pStartDate date;
	declare pEmployeeID int;
	declare counter int;
    
	select  count(*) into counter from employees;
    
    while counter >= 0 do
		select employeeID, startDate into pEmployeeID, pStartDate from employees limit counter, 1;
        if pStartDate >= DATE_SUB(curdate(), INTERVAL 5 YEAR) then
			set pVacationDays = 15;
		else
			set pVacationDays = 10;
        end if;
        
        update employees
        set vacationDays = pVacationDays
        where employeeID = pEmployeeID;
        set counter = counter - 1;
    end while;
END $$

CREATE PROCEDURE calculateVacationDays2()
BEGIN
	set SQL_SAFE_UPDATES = 0;
	update employees
	set vacationDays = 
    case 
		when startDate >= DATE_SUB(curdate(), INTERVAL 5 YEAR) then 15
        else 10
	end;
	set SQL_SAFE_UPDATES = 1;
END $$

CREATE PROCEDURE dynamicLoopExample(
	in salaryThreshold int
)
BEGIN
	declare pEmployeeID int;
	declare employeeSalary int;
	declare counter int;
    set employeeSalary = 0;
	select  count(*) into counter from employees;
	lop: loop
    
		if counter < 0 then
			leave lop;
		end if;
        
        select employeeID, salary 
        into pEmployeeID, employeeSalary 
        from employees limit counter, 1;
        
        if employeeSalary > salaryThreshold then
			leave lop;
		end if;
        
		update employees
        set salary = salary * 1.1
        where employeeID = pEmployeeID;
        
        set counter = counter -1;
 
    end loop;
END $$

DELIMITER ;
