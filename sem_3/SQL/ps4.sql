CREATE TABLE Customer (
    customerid BIGINT PRIMARY KEY,
    firstname VARCHAR(50),
    lastname VARCHAR(50),
    city VARCHAR(50),
    state VARCHAR(50)
);

CREATE TABLE Items_ordered (
    customerid BIGINT,
    order_date DATE,
    item VARCHAR(50),
    quantity INT,
    price NUMERIC(10,2)
);

DROP TABLE Items_ordered;

INSERT INTO Customer VALUES
        (10101, 'John', 'Gray', 'Lynden', 'Washington'),
        (10298, 'Leroy', 'Brown', 'Pinetop', 'Arizona'),
        (10299, 'Elroy', 'Keller', 'Snoqualmie', 'Washington'),
        (10315, 'Lisa', 'Jones', 'Oshkosh', 'Wisconsin'),
        (10325, 'Ginger', 'Schultz', 'Pocatello', 'Idaho'),
        (10329, 'Kelly', 'Mendoza', 'Kailua', 'Hawaii'),
        (10330, 'Shawn', 'Dalton', 'Cannon Beach', 'Oregon'),
        (10338, 'Michael', 'Howell', 'Tillamook', 'Oregon'),
        (10339, 'Anthony', 'Sanchez', 'Winslow', 'Arizona'),
        (10408, 'Elroy', 'Cleaver', 'Globe', 'Arizona'),
        (10410, 'Mary Ann', 'Howell', 'Charleston', 'South Carolina'),
        (10413, 'Donald', 'Davids', 'Gila Bend', 'Arizona'),
        (10419, 'Linda', 'Sakahara', 'Nogales', 'Arizona'),
        (10429, 'Sarah', 'Graham', 'Greensboro', 'North Carolina'),
        (10438, 'Kevin', 'Smith', 'Durango', 'Colorado'),
        (10439, 'Conrad', 'Giles', 'Telluride', 'Colorado'),
        (10449, 'Isabela', 'Moore', 'Yuma', 'Arizona');

INSERT INTO Items_ordered VALUES
    (10330, STR_TO_DATE('30-Jun-1999', '%d-%b-%Y'), 'Pogo stick', 1, 28.00),
    (10101, STR_TO_DATE('30-Jun-1999', '%d-%b-%Y'), 'Raft', 1, 58.00),
    (10298, STR_TO_DATE('01-Jul-1999', '%d-%b-%Y'), 'Skateboard', 1, 33.00),
    (10101, STR_TO_DATE('01-Jul-1999', '%d-%b-%Y'), 'Life Vest', 4, 125.00),
    (10299, STR_TO_DATE('06-Jul-1999', '%d-%b-%Y'), 'Parachute', 1, 1250.00),
    (10339, STR_TO_DATE('27-Jul-1999', '%d-%b-%Y'), 'Umbrella', 1, 4.50),
    (10449, STR_TO_DATE('13-Aug-1999', '%d-%b-%Y'), 'Unicycle', 1, 180.79),
    (10439, STR_TO_DATE('14-Aug-1999', '%d-%b-%Y'), 'Ski Poles', 2, 25.50),
    (10101, STR_TO_DATE('18-Aug-1999', '%d-%b-%Y'), 'Rain Coat', 1, 18.30),
    (10449, STR_TO_DATE('01-Sep-1999', '%d-%b-%Y'), 'Snow Shoes', 1, 45.00),
    (10439, STR_TO_DATE('18-Sep-1999', '%d-%b-%Y'), 'Tent', 1, 88.00),
    (10298, STR_TO_DATE('19-Sep-1999', '%d-%b-%Y'), 'Lantern', 2, 29.00),
    (10410, STR_TO_DATE('28-Oct-1999', '%d-%b-%Y'), 'Sleeping Bag', 1, 89.22),
    (10438, STR_TO_DATE('01-Nov-1999', '%d-%b-%Y'), 'Umbrella', 1, 6.75),
    (10438, STR_TO_DATE('02-Nov-1999', '%d-%b-%Y'), 'Pillow', 1, 8.50),
    (10298, STR_TO_DATE('01-Dec-1999', '%d-%b-%Y'), 'Helmet', 1, 22.00),
    (10449, STR_TO_DATE('15-Dec-1999', '%d-%b-%Y'), 'Bicycle', 1, 380.50),
    (10449, STR_TO_DATE('22-Dec-1999', '%d-%b-%Y'), 'Canoe', 1, 280.00),
    (10101, STR_TO_DATE('30-Dec-1999', '%d-%b-%Y'), 'Hoola Hoop', 3, 14.75),
    (10330, STR_TO_DATE('01-Jan-2000', '%d-%b-%Y'), 'Flashlight', 4, 28.00),
    (10101, STR_TO_DATE('02-Jan-2000', '%d-%b-%Y'), 'Lantern', 1, 16.00),
    (10299, STR_TO_DATE('18-Jan-2000', '%d-%b-%Y'), 'Inflatable Mattress', 1, 38.00),
    (10438, STR_TO_DATE('18-Jan-2000', '%d-%b-%Y'), 'Tent', 1, 79.99),
    (10413, STR_TO_DATE('19-Jan-2000', '%d-%b-%Y'), 'Lawnchair', 4, 32.00),
    (10410, STR_TO_DATE('30-Jan-2000', '%d-%b-%Y'), 'Unicycle', 1, 192.50),
    (10315, STR_TO_DATE('02-Feb-2000', '%d-%b-%Y'), 'Compass', 1, 8.00),
    (10449, STR_TO_DATE('29-Feb-2000', '%d-%b-%Y'), 'Flashlight', 1, 4.50),
    (10101, STR_TO_DATE('08-Mar-2000', '%d-%b-%Y'), 'Sleeping Bag', 2, 88.70),
    (10298, STR_TO_DATE('18-Mar-2000', '%d-%b-%Y'), 'Pocket Knife', 1, 22.38),
    (10449, STR_TO_DATE('19-Mar-2000', '%d-%b-%Y'), 'Canoe paddle', 2, 40.00),
    (10298, STR_TO_DATE('01-Apr-2000', '%d-%b-%Y'), 'Ear Muffs', 1, 12.50),
    (10330, STR_TO_DATE('19-Apr-2000', '%d-%b-%Y'), 'Shovel', 1, 16.75);

# 1
SELECT customerid, item, price FROM Items_ordered WHERE customerid = 10049;

# 2
SELECT * FROM Items_ordered WHERE item = 'Tent';

# 3
SELECT customerid, order_date, quantity FROM Items_ordered WHERE ASCII(LEFT(item, 1)) = ASCII('S');

# 4
SELECT MAX(price) FROM Items_ordered;

# 5
SELECT AVG(price) FROM Items_ordered WHERE MONTHNAME(order_date) = 'December';

# 6
SELECT MIN(price) FROM Items_ordered WHERE item = 'Tent';

# 7
SELECT state, COUNT(*) FROM Customer ORDER BY state;

# 8
SELECT item, MAX(price), MIN(price) FROM Items_ordered GROUP BY item;

# 9
SELECT customerid, COUNT(*) FROM Items_ordered GROUP BY customerid;

# 10
SELECT state, COUNT(*) FROM Customer GROUP BY state HAVING COUNT(*) > 1;

# 11
SELECT firstname, lastname, city FROM Customer ORDER BY lastname DESC;

# 12
SELECT item, price FROM Items_ordered WHERE price > 10 ORDER BY price;

# 13
SELECT customerid, order_date, item FROM Items_ordered WHERE item NOT IN ('Snow Shoes', 'Ear Muffs');

# 14
SELECT item, price FROM Items_ordered WHERE ASCII(LEFT(item, 1)) = ASCII('S') OR ASCII(LEFT(item, 1)) = ASCII('P') OR ASCII(LEFT(item, 1)) = ASCII('F');

# 15
SELECT order_date, item, price FROM Items_ordered WHERE price BETWEEN 10 AND 80;

# 16
SELECT firstname, city, state FROM Customer WHERE state IN ('Arizona', 'Washington', 'Oklahoma', 'Colorado', 'Hawaii');

# 17
SELECT item, price/quantity AS unit_price FROM Items_ordered;

# 18
SELECT C.customerid, C.firstname, C.lastname, I.order_date, I.item, I.price FROM Customer C INNER JOIN Items_ordered I on C.customerid = I.customerid;

# 19
SELECT C.firstname, C.lastname, I.order_date FROM Customer C INNER JOIN Items_ordered I on C.customerid = I.customerid WHERE C.customerid = 10101;

# 20
SELECT YEAR(order_date) AS year, SUM(price) AS sales FROM Items_ordered GROUP BY YEAR(order_date);

# 21
SELECT * FROM Customer WHERE customerid NOT IN (SELECT DISTINCT customerid FROM Items_ordered);

# 23
SELECT * FROM Customer C INNER JOIN Items_ordered I on C.customerid = I.customerid WHERE I.price > 800;

# 24
SELECT C.*, I.quantity FROM Customer C INNER JOIN Items_ordered I on C.customerid = I.customerid;

# 25
SELECT MONTHNAME(order_date) FROM Items_ordered GROUP BY MONTHNAME(order_date) ORDER BY COUNT(*) DESC LIMIT 1;

# 26
SELECT DISTINCT I.item from Items_ordered I INNER JOIN Customer C ON I.customerid = C.customerid WHERE C.state = 'Colorado';

# 27
SELECT I.* FROM Items_ordered I INNER JOIN Customer C on I.customerid = C.customerid WHERE I.price > 350 AND C.state IN ('Colorado', 'North Carolina', 'Washington', 'South Carolina');

# 28
SELECT YEAR(order_date), SUM(price) FROM Items_ordered WHERE customerid = 10101 GROUP BY YEAR(order_date);

# 29
SELECT C.* FROM Customer C INNER JOIN Items_ordered I on C.customerid = I.customerid WHERE C.state = 'Colorado' AND I.item = 'Umbrella';

# 30
SELECT DISTINCT customerid FROM Items_ordered WHERE YEAR(order_date) IN (1999, 2000);
