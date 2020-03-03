#include<iostream>
using namespace std;

class Book
{
    string title, author;
    public: 
        void setBook(string, string);
        void displayBook();
};

class Fiction:public Book
{
    int grade;
    public:
        void setFiction(string, string, int);
        void displayFiction();
};

class NonFiction:public Book
{
    int noOfPages;
    public:
        void setNonFiction(string, string, int);
        void displayNonFiction();
};

void Book::setBook(string title, string author)
{
    this->title = title;
    this->author = author;
}

void Book::displayBook()
{
    cout << "The name of the book is " << title << " and the author is " << author << endl;
}

void Fiction::setFiction(string title, string author, int grade)
{
    Book::setBook(title, author);
    this->grade = grade;
}

void Fiction::displayFiction()
{
    Book::displayBook();
    cout << " The grade is "<< grade << endl;
}

void NonFiction::setNonFiction(string title, string author, int noOfPages)
{
    Book::setBook(title, author);
    this->noOfPages = noOfPages;
}

void NonFiction::displayNonFiction()
{
    Book::displayBook();
    cout << " The page count is "<< noOfPages << endl;
}

int main()
{
    Book B;
    B.setBook("Life is a steep learning curve","Tarun Pritam");
    B.displayBook();
}