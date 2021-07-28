SET foreign_key_checks = 0;
drop table Publisher;
drop table Book;
drop table Author;
drop table Writes;
drop procedure PopulateBookCount;
drop trigger UpdateBookCount;
SET foreign_key_checks = 1;

# RDBMS Final Lab Examination
USE exam193;
# Table Defenitions
CREATE TABLE Publisher
(
    PublisherID VARCHAR(20),
    Name        VARCHAR(20),
    Place       VARCHAR(20),
    CONSTRAINT pk_PID PRIMARY KEY (PublisherID),
    CONSTRAINT PID_check CHECK (PublisherID like 'P%'),
    CONSTRAINT place_check CHECK (Place in ('Delhi', 'USA', 'China'))
);

CREATE TABLE Book
(
    ISBN        NUMERIC(6),
    Title       VARCHAR(50),
    Year        YEAR,
    PublisherID VARCHAR(20),
    Pages       NUMERIC(5),
    Price       NUMERIC(5, 2),
    Language    VARCHAR(10),
    CONSTRAINT ISBN_check CHECK ( ISBN REGEXP '^111[0-9]{3}'),
    CONSTRAINT title_check CHECK (ASCII(LEFT(Title, 1)) BETWEEN ASCII('A') AND ASCII('Z')),
    CONSTRAINT year_check CHECK (Year > 1999),
    CONSTRAINT PK_ISBN PRIMARY KEY (ISBN),
    CONSTRAINT language_check CHECK (Language in ('English', 'French', 'Hindi')),
    CONSTRAINT FKB_PID FOREIGN KEY (PublisherID) REFERENCES Publisher (PublisherID)
);

CREATE TABLE Author
(
    AuthorID    VARCHAR(4),
    Name        VARCHAR(20),
    Birthdate   DATE,
    Nationality VARCHAR(20),
    CONSTRAINT AID_check CHECK ( AuthorID REGEXP '^A[0-9]{3}'),
    CONSTRAINT name_check CHECK (ASCII(LEFT(Name, 1)) BETWEEN ASCII('A') AND ASCII('Z')),
    CONSTRAINT PK_AID PRIMARY KEY (AuthorID)
);

CREATE TABLE Writes
(
    ISBN     NUMERIC(6),
    AuthorID VARCHAR(4),
    CONSTRAINT FK_PID FOREIGN KEY (ISBN) REFERENCES Book (ISBN),
    CONSTRAINT FK_AID FOREIGN KEY (AuthorID) REFERENCES Author (AuthorID)
);

# Populating the Tables
INSERT INTO Publisher
VALUES ('P501', 'Narosa', 'Delhi'),
       ('P203', 'McGrawHill', 'China'),
       ('P604', 'Pearson', 'USA'),
       ('P502', 'Pleasent', 'Delhi');

INSERT INTO Book
VALUES (111245, 'C Programming', 2000, 'P501', 200, 250.00, 'English'),
       (111753, 'System Software', 2005, 'P203', 350, 500.00, 'French'),
       (111467, 'Database Management', 2004, 'P604', 550, 390.50, 'English'),
       (111555, 'Object Oriented Programming', 2001, 'P501', 345, 400.00, 'Hindi'),
       (111654, 'Data Structures', 2004, 'P203', 530, 600.00, 'English');

INSERT INTO Author
VALUES ('A101', 'Dennis ritchie', STR_TO_DATE('12,04,1965', '%d,%m,%Y'), 'Indian'),
       ('A102', 'Dhamdhere', STR_TO_DATE('30,01,1958', '%d,%m,%Y'), 'American'),
       ('A103', 'Ramez elmasri', STR_TO_DATE('16,09,1956', '%d,%m,%Y'), 'Indian'),
       ('A104', 'Herbert schildt', STR_TO_DATE('26,06,1949', '%d,%m,%Y'), 'American'),
       ('A105', 'Thomas carman', STR_TO_DATE('17,05,1948', '%d,%m,%Y'), 'Indian'),
       ('A106', 'Ragu ramakrishnan', STR_TO_DATE('20,08,1961', '%d,%m,%Y'), 'Indian');

INSERT INTO Writes
VALUES (111245, 'A101'),
       (111753, 'A102'),
       (111654, 'A105'),
       (111467, 'A103'),
       (111245, 'A104'),
       (111467, 'A106'),
       (111467, 'A101'),
       (111245, 'A102');

# 1
SELECT *
FROM Book B
         LEFT OUTER JOIN Writes W ON B.ISBN = W.ISBN
WHERE W.AuthorID is NULL;

# 2
SELECT Title
FROM Book
WHERE Language = 'English'
  AND PublisherID = 'P501';

# 3
SELECT A.Name
FROM Writes W
         INNER JOIN Author A ON W.AuthorID = A.AuthorID
GROUP BY A.AuthorID
HAVING COUNT(*) > 1;

# 4
SELECT B.Title
FROM Book B
         INNER JOIN Publisher P ON B.PublisherID = P.PublisherID
WHERE P.Place = 'Delhi';

# 5
# Table Defenition
CREATE TABLE Book_Count
(
    AuthorID  VARCHAR(4),
    noOfBooks NUMERIC(3),
    CONSTRAINT BCPK_AID PRIMARY KEY (AuthorID),
    CONSTRAINT BCFK_AID FOREIGN KEY (AuthorID) REFERENCES Author (AuthorID)
);

# Creating Procedure
DELIMITER //
CREATE PROCEDURE PopulateBookCount()
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE author_id VARCHAR(4);
    DECLARE book_count NUMERIC(3);
    DECLARE author_cursor CURSOR FOR SELECT AuthorID FROM Author;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;

    OPEN author_cursor;

    get_author:
    LOOP
        FETCH author_cursor INTO author_id;
        IF (finished = 1) THEN
            LEAVE get_author;
        END IF;

        SELECT COUNT(*)
        INTO book_count
        FROM Book B
                 INNER JOIN Writes W ON B.ISBN = W.ISBN
        WHERE W.AuthorID = author_id;

        INSERT INTO Book_Count VALUES (author_id, book_count);

    END LOOP;

    CLOSE author_cursor;
END //
DELIMITER ;

# Calling Procedure
CALL PopulateBookCount();

# Checking working of Procedure
SELECT *
FROM Book_Count;

# 6
# Creating Trigger
DELIMITER //
CREATE TRIGGER UpdateBookCount
    AFTER INSERT
    ON Writes
    FOR EACH ROW
BEGIN
    UPDATE Book_Count SET noOfBooks = noOfBooks + 1 WHERE AuthorID = New.AuthorID;
END //
DELIMITER ;

# Test Cases for Trigger
INSERT INTO Book
VALUES (111954, 'Drawing', 2004, 'P501', 500, 600.00, 'English');
INSERT INTO Writes
VALUES (111954, 'A103');
