USE 19pw33;
SHOW TABLES;

SET foreign_key_checks = 0;
drop table EMP;
drop table DEPARTMENT;
drop table ITEM;
drop table SALES;
SET foreign_key_checks = 1;

show tables;

CREATE TABLE EMP (
    Empno INT PRIMARY KEY,
    Empname VARCHAR(30),
    Empsalary INT,
    Deptname VARCHAR(30) NULL,
    Bossno INT NOT NULL,
    FOREIGN KEY (Bossno) REFERENCES EMP(Empno)
);

CREATE TABLE DEPARTMENT (
    Deptname VARCHAR(30) PRIMARY KEY,
    Deptfloor INT,
    Deptphone INT,
    MgrId INT NOT NULL,
    FOREIGN KEY (MgrId) REFERENCES EMP(Empno)
);

CREATE TABLE ITEM (
    itemname VARCHAR(30) PRIMARY KEY,
    itemtype CHARACTER,
    itemcolor varchar(10)
);

CREATE TABLE SALES (
    Salesno INT PRIMARY KEY,
    Saleqty INT,
    itemname varchar(30) NOT NULL,
    Deptname VARCHAR(30) NOT NULL,
    FOREIGN KEY (itemname) REFERENCES ITEM(itemname),
    FOREIGN KEY (Deptname) REFERENCES DEPARTMENT(Deptname)
);

ALTER TABLE EMP
    ADD FOREIGN KEY (Deptname) REFERENCES DEPARTMENT(Deptname);



