# selecting the database
show tables;
use 19pw33;

# Question 1
create table EMPTABLE (
    Empid numeric(6) primary key,
    Name varchar(10) not null check
        (ascii(left(Name, 1)) between ascii('A') and ascii('Z')),
    City varchar(10) check
        (ascii(left(City, 1)) between ascii('A') and ascii('Z')),
    DOB date not null,
    Sex character(1) check
        (Sex in ('M', 'F')),
    DOJ date not null,
    Salary numeric(8, 2) check
        (Salary between 15000 and 50000),
    Department varchar(10) check
        (Department in ('ACC', 'FIN', 'EDP'))
);

# Some useful queries
desc EMPTABLE;
select * from EMPTABLE;
truncate EMPTABLE;
drop table EMPTABLE;

# Question 2
INSERT INTO EMPTABLE
VALUES (1001, 'Anish', 'Chennai', '1966-04-21', 'M', '1966-06-10', 17000, 'ACC'),
       (1002, 'Anandi', 'Ooty', '1975-09-11', 'F', '1997-06-17', 15000, 'FIN'),
       (1003, 'Shiva', 'Kambam', '1966-02-07', 'M', '1991-04-21', 21000, 'EDP'),
       (1004, 'Deepa', 'Trichi', '1967-02-14', 'M', '1990-04-21', 12000, 'FIN'),
       (1005, 'Engela', null, '1970-03-23', 'F', '1986-04-21', 32000, 'EDP'),
       (1006, 'Krish', 'Trichi', '1970-07-14', 'F', '1989-03-21', 15000, 'ACC'),
       (1007, 'Kamal', 'Ooty', '1966-07-14', 'M', '1990-03-04', 12000, 'FIN'),
       (1008, 'Neela', 'Madurai', '1969-06-27', 'F', '1990-04-07', 25000, 'EDP'),
       (1009, 'Bala', 'Coimbatore', '1962-10-29', 'M', '1993-04-21', 20000, 'ACC'),
       (1010, 'Rajesh', 'Pollachi', '1966-04-21', 'M', '1993-10-12', 17000, 'FIN'),
       (1011, 'Rekha', 'Coimbatore', '1970-04-21', 'F', '1999-12-14', 20000, 'ACC'),
       (1012, 'Xavier', 'Madurai', '1971-04-21', 'M', '1997-03-12', 20000, 'ACC'),
       (1013, 'Vinotha', 'Trichi', '1972-04-21', 'F', '1994-04-21', 17000, 'ACC');

# Question 3

# 1
select * from EMPTABLE;

# 2
select Empid, Name, City, Salary from EMPTABLE;

# 3
select Empid from EMPTABLE where Name = 'Bala';

# 4
select * from EMPTABLE where Sex = 'M';

# 5
select * from EMPTABLE where City = 'Coimbatore';

# 6
select * from EMPTABLE where City in ('Coimbatore', 'Trichy', 'Chennai');

# 7
select Name from EMPTABLE where City is null;

# 8
select distinct City from EMPTABLE where City is not null;

# 9
select Empid, Salary * 2 from EMPTABLE;

# 10
select Name, City from EMPTABLE where Salary > 50000;

# 11
select Empid, Name, Salary, Salary * (5 / 100) as `Inscreased Salary` from EMPTABLE;

# 12
select Empid, Name, Salary, Salary * (5 / 100) as `Inscreased Salary` from EMPTABLE order by `Inscreased Salary` desc;

# 13
select * from EMPTABLE order by Name;
select * from EMPTABLE order by Salary desc;

# 14
select count(Empid) as No_Of_Employees from EMPTABLE;

# 15
select count(distinct Department) as No_Of_Departments from EMPTABLE;

# 16
select count(Department) from EMPTABLE where Department = 'FIN';

# 17
select count(Sex) from EMPTABLE where Sex = 'M';

# 18
select Name, Salary from EMPTABLE where Salary = (select max(Salary) from EMPTABLE);

# 19
select Name, Salary from EMPTABLE where Salary = (select min(Salary) from EMPTABLE);

# 20
select Department, sum(Salary) from EMPTABLE group by Department;

# 21
select Empid from EMPTABLE where Empid != 1002;

# 22
select * from EMPTABLE where left(Name, 1) = 'A';

# 23
select * from EMPTABLE where DOB < '1991-01-01';

# 24
select Name from EMPTABLE where Salary between 20000 and 40000;

# 25
select * from EMPTABLE where Salary > 20000;

# 26
select * from EMPTABLE where Salary > 20000 and Department = 'ACC';

# 27 Todo
select * from EMPTABLE where Salary > 20000;

# 28
select Name, Salary, Department from EMPTABLE where (Department, Salary) in (select Department, min(Salary)
from EMPTABLE group by Department);

# 29
select Department, count(Sex) as No_Of_Males from EMPTABLE where Sex = 'M' group by Department;

# 30
select Name, timestampdiff(day, DOJ, current_timestamp) as Experience from EMPTABLE;

# 31
select Name, timestampdiff(year, DOJ, current_timestamp) as Experience from EMPTABLE;

# 32
select Name, timestampdiff(year, DOB, current_timestamp) as Age from EMPTABLE;

# 33
select * from EMPTABLE where DOB in (select min(DOB) from EMPTABLE);

# 34
select timestampdiff(year, DOB, current_timestamp) as Age from EMPTABLE where DOB in (select min(DOB) from EMPTABLE);

# 35
select Name, City from EMPTABLE where City is not null order by City;

# 36
select Name, DOB from EMPTABLE where month(DOB) = '01';

# 37
select Department, count(Department) from EMPTABLE group by Department;

# 38 No Phone Number

# 39
select Sex, avg(timestampdiff(year, DOB, current_timestamp)) as Age from EMPTABLE group by Sex;

# 40
select Name from EMPTABLE where month(current_date) - month(DOB) = 0;

# 41
select avg(Salary) as Avg_Salary from EMPTABLE;

# 42
select Department, avg(Salary) as Avg_Salary from EMPTABLE group by Department;

# 43
select Department, sum(Salary) as Sum_Salary from EMPTABLE group by Department;

# 44
select count(*) from EMPTABLE where Salary > 30000;

# 45
select max(Salary) from EMPTABLE;

# 46
select Department, max(Salary) from EMPTABLE group by Department;

# 47
select count(*) from EMPTABLE where Sex = 'F' and City = 'Coimbatore';

# 48
select * from EMPTABLE where month(DOB) not in (10, 03);

# 49
select Department, count(Sex) as No_Of_Females from EMPTABLE where Sex = 'F' group by Department;

# 50
select Name, City, DOB from EMPTABLE;

# 51
select max(Salary) - min(Salary) as SalaryDiff from EMPTABLE;

# 52
select Department, count(Distinct City) from EMPTABLE group by Department having count(distinct City) > 1;

# 53
select Department from EMPTABLE group by Department order by count(*) desc limit 1;

# 54
select Name from EMPTABLE where Sex = 'M' and year(DOB) = '1990' order by DOB desc limit 1;

# 55
select Name from EMPTABLE where Sex = 'F' and year(DOB) = '1990' order by DOB limit 1;

# 56
select Name from EMPTABLE where timestampdiff(year, DOB, current_timestamp) < 32;

# 57
select * from EMPTABLE where timestampdiff(day, DOB, current_timestamp) < (select timestampdiff(day, DOB, current_timestamp) from EMPTABLE where Empid = 1007);

# 58
select year(DOB) from EMPTABLE group by year(DOB) order by count(*) desc limit 1;

# 59
select month(DOB) from EMPTABLE group by month(DOB) order by count(*) desc limit 1;

# 60
select Name from EMPTABLE where Sex = 'M' and Salary < (select avg(Salary) from EMPTABLE where Sex = 'F');

# 61
select Name from EMPTABLE where Salary in (select Salary from EMPTABLE group by Salary having count(*) > 1);

# 62
select count(distinct Department) as No_Of_Departments from EMPTABLE;

# 63
select Name from EMPTABLE where length(Name) <= 5;

# 64
select Name from EMPTABLE where lower(Name) like '%e%';

# 65 Todo
select * from EMPTABLE where Empid in (select Department from EMPTABLE where City = 'Trichi' group by Department having count(Department) = 1);

# 66
select * from EMPTABLE order by City;

# 67
select City, count(*) as Count from EMPTABLE group by City;

# 68
select Name from EMPTABLE where (City, Salary)  = (select City, Salary from EMPTABLE group by City, Salary having count(City) > 1 and count(Salary) > 1);

# 69
select distinct Department from EMPTABLE where Department not in (select Department from EMPTABLE where City = 'Trichi' group by Department);

# 70 Todo
select Department, count(distinct Salary) from EMPTABLE group by Department;

# 71
select Name from EMPTABLE where Sex = 'F' and Salary in (select Salary from EMPTABLE where Sex = 'F' group by Salary having count(Salary) > 1);

# 72
alter table EMPTABLE modify Name varchar(15) not null;

# 73
alter table EMPTABLE add Age numeric(3);

# 74 Todo
insert into EMPTABLE (Age) values (select timestampdiff(year, DOB, current_timestamp) from EMPTABLE);

# 75
alter table EMPTABLE change DOB DateofBirth date;

# 76
alter table EMPTABLE drop Age;

# 77
select concat(Name, ' of ', Department, ' department comes from ', City ) as Report from EMPTABLE;

# 78
select Name from EMPTABLE where Department = 'ACC' order by 1 desc;
# The Names of the employees are displayed in descending alphabetical order

# 79
alter table EMPTABLE modify DOJ date;

# 80
select upper(Name) as NAME, upper(City) as CITY from EMPTABLE;

# 81
select month(DateofBirth) from EMPTABLE group by month(DateofBirth) order by count(*) desc limit 1;

# 82
select Name from EMPTABLE where Sex = 'M' and Salary < (select avg(Salary) from EMPTABLE where Sex = 'F');

# 83
select Name from EMPTABLE where Sex = 'F' and Salary > (select max(Salary) from EMPTABLE where Sex = 'M');

# 84
insert into EMPTABLE value ('1003', 'Sam', 'Erode', '1972-06-24', 'M', '1997-01-30', '60000', 'EDP');

# 85
delete from EMPTABLE where Name = 'Engela';