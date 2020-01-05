#include<iostream>
#include<stdlib.h>
using namespace std;

class Matrix
{
    int **matrix;
    int row,col;
    static int count;
    public:
        void read();
        void display();
        Matrix(int ,int);
        static int retCount(){return count;}
        Matrix add(Matrix);
};

int Matrix::count;

void Matrix::read()
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            cin>>matrix[i][j];
}

void Matrix::display()
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cout<<matrix[i][j]<<"\t";
        cout<<endl;
    }
}

Matrix::Matrix(int row,int col)
{
    this->row=row;
    this->col=col;
    matrix=new int*[row];
    for(int i=0;i<row;i++)
        matrix[i]=new int[col];
    count++;
}

Matrix Matrix::add(Matrix m)
{
    int i,j;
    Matrix sum(row,col);
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            sum.matrix[i][j]=matrix[i][j]+m.matrix[i][j];
    return sum;
}

int main()
{
    Matrix m1(3,3),m2(3,3),sum(3,3);
    cout<<"Enter a 3x3 matrix:\n";
    m1.read();
    cout<<"Enter another 3x3 matrix:\n";
    m2.read();
    sum=m1.add(m2);
    sum.display();
    cout<<"The number of matrices created in this program: "<<Matrix::retCount()<<endl;
}