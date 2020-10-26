USE 19pw33;

CREATE TABLE IF NOT EXISTS COURSES
(
    CCODE VARCHAR(10),
    CNAME VARCHAR(50) NOT NULL ,
    COURSEFEE NUMERIC(6 ,2) NOT NULL ,
    DURATION NUMERIC(3) NOT NULL ,
    PREREQ VARCHAR(100),
    CONSTRAINT ccode_pk PRIMARY KEY (CCODE)
);

CREATE TABLE IF NOT EXISTS BATCHES
(
    BATCHCODE   VARCHAR(12) CHECK ( BATCHCODE REGEXP ('^[A-Z]{2,6}[0-9]{6}$')),
    CCODE   VARCHAR(10),
    STDATE  DATE ,
    ENDDATE DATE ,
    TIMINGS VARCHAR(20),
    CONSTRAINT ccode_fk FOREIGN KEY (CCODE) REFERENCES COURSES(CCODE),
    CONSTRAINT bcode_pk PRIMARY KEY (BATCHCODE),
    CONSTRAINT endtime_check CHECK ( STDATE < ENDDATE )
);

CREATE TABLE IF NOT EXISTS STUDENTS
(
    ADMNO   NUMERIC(5),
    BATCHCODE   VARCHAR(12),
    ROLLNO  NUMERIC(3) ,
    FULLNAME    VARCHAR(50),
    FATHERNAME  VARCHAR(50),
    EMAIL   VARCHAR(50) UNIQUE,
    PHONENO VARCHAR(20) UNIQUE CHECK ( PHONENO REGEXP ('(\+[0-9]{2}-[0-9]{10})|[0-9]{10}')) ,
    DJ DATE,
    CONSTRAINT bcode_fk FOREIGN KEY (BATCHCODE) REFERENCES BATCHES(BATCHCODE),
    CONSTRAINT admno_pk PRIMARY KEY (ADMNO)
);

CREATE TABLE IF NOT EXISTS PAYMENTS
(
    RCPTNO  NUMERIC(5),
    ADMNO   NUMERIC(5),
    AMOUNT  NUMERIC(6,2),
    PAYDATE DATE,
    REMARKS VARCHAR(200),
    CONSTRAINT rcptno_pk PRIMARY KEY (RCPTNO),
    CONSTRAINT admno_fk FOREIGN KEY (ADMNO) REFERENCES STUDENTS(ADMNO)
);

#COURSES
INSERT INTO COURSES VALUES
('ORACLE11G','ORACLE DATABASE 11G',2500,40,'COMPUTER KONWLEDGE'),
('JAVASE6.0','JAVA SE 6.0',2500,40,'C LANGUAGE'),
('DOTNET3.5','MICROSOFT.NET 3.5',3750,80,'C LANGUAGE & SQL');

#BATCHES
INSERT INTO BATCHES VALUES
('ORA130508','ORACLE11G','08-05-13','17-06-08','4:30 TO 6:00 PM'),
('DOTNET130508','DOTNET3.5','08-05-13','08-06-26','7:00 TO 9:00 AM'),
('ORA270608','ORACLE11G','08-06-27',NULL,'5:00 TO 6:00 PM'),
('JS270608','JAVASE6.0','08-06-27',NULL,'6:00 TO 7:00 PM');

#STUDENTS
INSERT INTO STUDENTS VALUES
(1,'ORA130508',1,'MICHEAL JORDON', 'TIM JORDON','MJORDON@YAHOO.COM', '9873737334','08-05-11'),
(2,'ORA130508',2,'TIM SLIM', 'TIM	KEN','TIM@YAHOO.COM', '9833334334','08-05-11'),
(3,'DOTNET130508',1,'HUNTER JASON', 'HUNTER BOB','JHUNTER@YAHOO.COM', '34344343','08-05-11'),
(4,'JS270608',1,'JAMES GOODWILL', 'JAMES ROBERTS','JAMES@YAHOO.COM', '9989898998','08-06-26'),
(5,'JS270608',2,'KENNY PETERSON', 'KENNY JACOB','KPERERSON@GMAIL.COM', '9983373333','08-06-27'),
(6,'ORA270608',1,'GLEN JHONSON', 'GLEN HENDRICK','GLEN@GMAIL.COM', '9898398985','08-06-28'),
(7,'ORA270608',2,'BATES KATHY', 'BATES ROBERTS','KATHY@YMAIL.COM', '234423232','08-06-30');

#PAYMENTS
INSERT INTO PAYMENTS VALUES
(1,1,300,'08-05-11','REG. FEE'),
(2,2,2500,'08-05-11','TOTAL FEE'),
(3,3,1000,'08-05-11','REG. FEE'),
(4,3,2750,'08-05-12',NULL),
(5,4,300,'08-06-26','REG. FEE'),
(6,5,300,'08-06-27','REG. FEE'),
(7,4,1700,'08-06-27',NULL),
(8,5,1700,'08-06-29',NULL),
(9,6,2500,'08-06-28','CHEQUE NO:3434343 SBI DWK'),
(10,7,2500,'08-06-30',NULL);

#SIMPLE QUERIES
#QN1
SELECT *
FROM STUDENTS
ORDER BY BATCHCODE ,DJ;

#QN2
SELECT *
FROM PAYMENTS
WHERE MONTH(PAYDATE) = 05 AND YEAR(PAYDATE) = 2008;

#QN3
SELECT *
FROM PAYMENTS
WHERE REMARKS LIKE '%CHEQUE%';

#QN4
SELECT FULLNAME,FATHERNAME,DJ,DATEDIFF(CURRENT_DATE,DJ) AS NO_OF_DAYS_OF_JOINING
FROM STUDENTS;

#QN5
SELECT BATCHCODE
FROM BATCHES
WHERE ENDDATE IS NOT NULL;

#QN6
SELECT BATCHCODE
FROM BATCHES
WHERE CCODE LIKE '%JAVASE%' OR '%ORACLE%';

#QN7
SELECT DATE_ADD(DJ,INTERVAL 7 DAY) AS DUE_DATE
FROM STUDENTS;

#QN8
SELECT *
FROM STUDENTS
WHERE DATE_ADD(DJ,INTERVAL 7 DAY) < CURRENT_DATE;

#QN9
SELECT * , (COURSEFEE*11)/10 AS INCREASED_FEE
FROM COURSES
WHERE COURSEFEE < 3000;

#QN10
SELECT FULLNAME
FROM STUDENTS
WHERE FULLNAME LIKE '%s%' AND
      FATHERNAME LIKE '%p%';

#QN11
SELECT BATCHCODE
FROM BATCHES
WHERE DATEDIFF(STDATE , CURRENT_DATE) > 45;

#Q12
SELECT BATCHCODE,STDATE,DATE_ADD(STDATE ,INTERVAL 2 MONTH) AS APPROXIMATE_ENDING
FROM BATCHES
WHERE ENDDATE IS NULL;

#QN13
SELECT DATEDIFF(ENDDATE,(DATE_ADD(STDATE,INTERVAL 2 MONTH ))) AS DIFFERENCE_BTW_ESTIMATED_AND_ACTUAL
FROM BATCHES
WHERE ENDDATE IS NOT NULL;

#QN14
INSERT INTO COURSES VALUE ('JAVAEEWEB','JAVA EE(WEB APPLICATIONS)',3000,40,'JAVA LANG AND SQL');

#QN15
UPDATE BATCHES
SET ENDDATE = DATE_ADD(CURRENT_DATE,INTERVAL -1 DAY )
WHERE BATCHCODE = 'JS130508';

#QN16
SELECT *
FROM BATCHES
WHERE YEAR(STDATE) = YEAR(CURRENT_DATE) - 1 AND YEAR(ENDDATE) = YEAR(CURRENT_DATE);

#QN17
SELECT *
FROM PAYMENTS
WHERE AMOUNT > 1000 OR
      (ADMNO BETWEEN 100 AND 150 AND
       DATEDIFF(PAYDATE ,CURRENT_DATE) < 10);

#QN18
UPDATE PAYMENTS
SET ADMNO = 120 AND PAYDATE = '08-06-01'
WHERE RCPTNO = 12;

#QN19
SELECT FULLNAME,BATCHCODE,DJ
FROM STUDENTS
ORDER BY FULLNAME,DJ;

#QN20
#SHOULD DO

#QROUPING
#QN1
SELECT SUM(AMOUNT) AS TOTAL_PAID_AMOUNT
FROM PAYMENTS
GROUP BY ADMNO;

#QN2
#TODO

#QN3
SELECT BATCHCODE,COUNT(ADMNO)
FROM STUDENTS
GROUP BY BATCHCODE;

#QN4
SELECT CCODE , MAX(STDATE) AS RECENTLY_STARTED
FROM BATCHES
GROUP BY CCODE ;

#QN5
SELECT SUM(AMOUNT) AS PAYMENT
FROM PAYMENTS
GROUP BY PAYDATE;

#QN6
SELECT CCODE,SUM(*) AS NUMBER_OF_BATCHES
FROM BATCHES
GROUP BY CCODE;

#QN7
SELECT MONTHNAME(PAYDATE) AS MONTH,SUM(AMOUNT) AS COLLECTED_AMOUNTS
FROM PAYMENTS
GROUP BY PAYDATE;

#QN8
SELECT B.BATCHCODE
FROM BATCHES B
INNER JOIN STUDENTS S on B.BATCHCODE = S.BATCHCODE
GROUP BY B.BATCHCODE HAVING COUNT(*) > 10;

#QN9
SELECT BATCHCODE,MIN(DJ) AS FIRST_ADMISSION,MAX(DJ) AS LAST_ADMISSION
FROM STUDENTS
GROUP BY BATCHCODE;

#QN10
SELECT CCODE
FROM BATCHES
GROUP BY CCODE HAVING COUNT(BATCHCODE) > 1;
#TODO

#QN11
#YEARWISE
SELECT YEAR(STDATE) AS BATCH_YEAR , COUNT(BATCHCODE)
FROM BATCHES
GROUP BY YEAR(STDATE);
#COURSEWISE
SELECT CCODE,COUNT(BATCHCODE)
FROM BATCHES
GROUP BY CCODE;

#QN12
#TODO

#QN13
SELECT COUNT(BATCHCODE) AS CURRENTLY_RUNNING
FROM BATCHES
WHERE ENDDATE IS NULL;

#QN14
SELECT SUBSTRING(EMAIL,LOCATE('@',EMAIL) + 1,LOCATE('.',EMAIL)-LOCATE('@',EMAIL) -1) AS SERVER,COUNT(ADMNO)
FROM STUDENTS
GROUP BY SERVER;

#QN15
SELECT S.BATCHCODE,COUNT(S.ADMNO) AS STUDENTS
FROM STUDENTS S
INNER JOIN BATCHES B on S.BATCHCODE = B.BATCHCODE
WHERE CCODE LIKE '%JAVA%'
GROUP BY S.BATCHCODE HAVING STUDENTS >10
ORDER BY STUDENTS;

#QN16
SELECT MONTH(CURRENT_DATE) AS CURRENT_MONTH,SUM(AMOUNT)
FROM PAYMENTS
WHERE MONTH(PAYDATE) = MONTH(CURRENT_DATE)
GROUP BY CURRENT_MONTH;

#QN17
SELECT YEAR(PAYDATE) AS YEAR , SUM(AMOUNT)
FROM PAYMENTS
WHERE YEAR(PAYDATE) = YEAR(CURRENT_DATE)
GROUP BY YEAR(PAYDATE);

#QN18
SELECT S.FULLNAME,COUNT(B.CCODE) AS COURSE_COUNT
FROM STUDENTS S
INNER JOIN BATCHES B on S.BATCHCODE = B.BATCHCODE
WHERE S.FULLNAME LIKE '%TIM%'
GROUP BY S.FULLNAME;

#QN19
SELECT PAYDATE
FROM PAYMENTS
GROUP BY PAYDATE HAVING SUM(AMOUNT) > 5000;

#QN20
SELECT BATCHCODE
FROM STUDENTS
WHERE DATEDIFF(CURRENT_DATE,DJ) < 10
GROUP BY DJ HAVING COUNT(*) > 5;

#JOINING
#QN1
SELECT BATCHCODE,CCODE,STDATE
FROM BATCHES ;

#QN2
SELECT P.RCPTNO,S.FULLNAME,P.AMOUNT,P.PAYDATE
FROM PAYMENTS P
INNER JOIN STUDENTS S on P.ADMNO = S.ADMNO
ORDER BY P.PAYDATE;

#QN3
SELECT B.CCODE,B.BATCHCODE,S.FULLNAME
FROM BATCHES B
INNER JOIN STUDENTS S on B.BATCHCODE = S.BATCHCODE;

#QN4
SELECT B.CCODE, COUNT(S.ADMNO) AS STUDENTS
FROM BATCHES B
INNER JOIN STUDENTS S on B.BATCHCODE = S.BATCHCODE
GROUP BY B.CCODE;

#QN5
SELECT S.FULLNAME,SUM(P.AMOUNT)
FROM STUDENTS S
INNER JOIN PAYMENTS P on S.ADMNO = P.ADMNO
WHERE S.BATCHCODE = 'ora130508'
GROUP BY S.ADMNO;

#QN6
#SAME QUES - QN5

#QN7
SELECT B.*
FROM COURSES C
INNER JOIN BATCHES B on C.CCODE = B.CCODE
WHERE COURSEFEE >3000;

#QN8
SELECT P.RCPTNO,S.FULLNAME,S.BATCHCODE,P.AMOUNT,P.PAYDATE
FROM STUDENTS S
INNER JOIN PAYMENTS P on S.ADMNO = P.ADMNO
WHERE DATEDIFF(CURRENT_DATE,P.PAYDATE) < 10;

#QN9
SELECT CCODE,BATCHCODE,STDATE,ENDDATE
FROM BATCHES
WHERE ENDDATE IS NOT NULL;

#QN10
SELECT S.FULLNAME,S.DJ,P.AMOUNT
FROM STUDENTS S
INNER JOIN PAYMENTS P on S.ADMNO = P.ADMNO
WHERE S.DJ = P.PAYDATE;

#QN11
SELECT C.CCODE,B.BATCHCODE
FROM BATCHES B
RIGHT JOIN COURSES C on C.CCODE = B.CCODE;

#QN12
SELECT *
FROM STUDENTS S
LEFT JOIN PAYMENTS P on S.ADMNO = P.ADMNO
WHERE P.AMOUNT IS NULL;

#QN13
SELECT BATCHCODE
FROM BATCHES
WHERE STDATE >(SELECT STDATE FROM BATCHES WHERE BATCHCODE = 'ORA130508');

#QN14
SELECT FULLNAME,BATCHCODE
FROM STUDENTS S
INNER JOIN PAYMENTS P on S.ADMNO = P.ADMNO
GROUP BY P.ADMNO HAVING (P.ADMNO,SUM(AMOUNT)) IN
    (SELECT P2.ADMNO,AMOUNT
     FROM COURSES C
     INNER JOIN BATCHES B on C.CCODE = B.CCODE
     INNER JOIN STUDENTS S on B.BATCHCODE = S.BATCHCODE
     INNER JOIN PAYMENTS P2 on S.ADMNO = P2.ADMNO
     WHERE S.DJ = P2.PAYDATE);

#QN15
SELECT *
FROM STUDENTS S
INNER JOIN BATCHES B2 on S.BATCHCODE = B2.BATCHCODE
INNER JOIN COURSES C2 on B2.CCODE = C2.CCODE
GROUP BY ADMNO HAVING (ADMNO,SUM(COURSEFEE)) NOT IN
(SELECT P2.ADMNO,SUM(AMOUNT)
     FROM COURSES C
     INNER JOIN BATCHES B on C.CCODE = B.CCODE
     INNER JOIN STUDENTS S on B.BATCHCODE = S.BATCHCODE
     INNER JOIN PAYMENTS P2 on S.ADMNO = P2.ADMNO
     GROUP BY P2.ADMNO);

#SUBQUERIES
#QN1
SELECT *
FROM PAYMENTS
WHERE ADMNO = (SELECT ADMNO FROM STUDENTS WHERE FULLNAME = 'JAMES GOODWILL');

#QN2
SELECT *
FROM PAYMENTS
WHERE ADMNO IN (SELECT ADMNO FROM STUDENTS WHERE BATCHCODE = 'ORA270608' );

#QN3
SELECT BATCHCODE
FROM BATCHES
WHERE CCODE IN (SELECT CCODE FROM COURSES WHERE DURATION > 40);

#QN4
SELECT FULLNAME
FROM STUDENTS
WHERE ADMNO IN (SELECT ADMNO FROM PAYMENTS WHERE MONTH(PAYDATE) = MONTH(CURRENT_DATE));

#QN5
SELECT FULLNAME
FROM STUDENTS
WHERE BATCHCODE IN (SELECT BATCHCODE FROM BATCHES WHERE CCODE LIKE '%ORACLE%');

#QN6
SELECT *
FROM STUDENTS
WHERE BATCHCODE IN (SELECT BATCHCODE FROM BATCHES WHERE ENDDATE IS NULL);

#QN7
SELECT FULLNAME,EMAIL
FROM STUDENTS
WHERE BATCHCODE IN (SELECT BATCHCODE FROM BATCHES WHERE DATEDIFF(CURRENT_DATE,ENDDATE)/30 BETWEEN 6 AND 7);
#HERE DATEDIFF(MONTH,CURRENT_DATE,ENDDATE) IS NOT WORKING
#TAKING 30 AS AVERAGE DAYS FOR A MONTH

#QN8
SELECT FULLNAME,EMAIL
FROM STUDENTS
WHERE BATCHCODE IN (SELECT BATCHCODE FROM BATCHES WHERE CCODE LIKE '%DOTNET%' AND DATEDIFF(CURRENT_DATE,ENDDATE)/30 BETWEEN 6 AND 7);

#QN9
SELECT BATCHCODE,COUNT(*) AS COUNT
FROM STUDENTS
GROUP BY BATCHCODE HAVING COUNT(*) < 10;

#QN10
SELECT P.RCPTNO,S.FULLNAME,S.BATCHCODE,P.AMOUNT,P.PAYDATE
FROM STUDENTS S
INNER JOIN PAYMENTS P on S.ADMNO = P.ADMNO
WHERE S.BATCHCODE IN (
    SELECT BATCHCODE
    FROM BATCHES
    WHERE CCODE LIKE '%ORACLE%');

#QN11
SELECT DISTINCT CCODE
FROM BATCHES
WHERE BATCHCODE IN (SELECT BATCHCODE FROM STUDENTS GROUP BY BATCHCODE HAVING COUNT(*) > 10);

#QN12
SELECT S.BATCHCODE , SUM(P.AMOUNT) AS COLLECTED_AMOUNT
FROM STUDENTS S
INNER JOIN PAYMENTS P on S.ADMNO = P.ADMNO
GROUP BY S.BATCHCODE HAVING SUM(P.AMOUNT) > 20000;

#QN13
SELECT FULLNAME
FROM STUDENTS
WHERE ADMNO NOT IN(SELECT ADMNO
                    FROM STUDENTS
                    WHERE DJ IN (SELECT STDATE FROM BATCHES) AND
                    BATCHCODE IN (SELECT BATCHCODE FROM BATCHES));


#QN14
SELECT BATCHCODE
FROM BATCHES
WHERE BATCHCODE IN
      (SELECT BATCHCODE
       FROM STUDENTS
       GROUP BY BATCHCODE
       ORDER BY COUNT(ADMNO) DESC)
LIMIT 3;

#QN15
UPDATE PAYMENTS
SET AMOUNT =
    (SELECT SUM(COURSEFEE)
     FROM COURSES C
     INNER JOIN BATCHES B on C.CCODE = B.CCODE
     INNER JOIN STUDENTS S on B.BATCHCODE = S.BATCHCODE
     WHERE ADMNO IN (SELECT ADMNO FROM PAYMENTS WHERE RCPTNO = '200')
     GROUP BY ADMNO)
WHERE RCPTNO = 200;