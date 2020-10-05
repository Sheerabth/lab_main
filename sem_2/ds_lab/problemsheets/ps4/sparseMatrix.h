#include <iostream>
#include <stdlib.h>
using namespace std;

class sparseMatrix{
    int **triple;
    int **sparse;
    int row,col,nonZero;
    public:
        void read();
        void displaySparse();
        void displayTriple();
        void findTripleRep();
        bool ifTwin(sparseMatrix);
        sparseMatrix transpose();
        sparseMatrix tripleTranspose();
        sparseMatrix addMatrix(sparseMatrix);
        sparseMatrix result(sparseMatrix);
};

void sparseMatrix::read()
{
    nonZero=0;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;
    sparse=(int **)calloc(row,sizeof(int *));
    for(int i=0;i<row;i++)
        sparse[i]=(int *)calloc(col,sizeof(int));
    cout<<"Enter the elements of the matrix:\n";
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            cin>>sparse[i][j];
            if(sparse[i][j])
                nonZero++;
        }
}

void sparseMatrix::displaySparse()
{
    int i,j;
    cout<<"The sparse matrix is:\n";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {

            cout<<sparse[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void sparseMatrix::displayTriple()
{
    int i,j;
    cout<<"The triple representation is\n";
    for(i=0;i<nonZero+1;i++)
    {
        for(j=0;j<3;j++)
            cout<<triple[i][j]<<"\t";
        cout<<endl;
    }
}

void sparseMatrix::findTripleRep()
{   
    int i,j,k=1;
    triple=(int **)calloc((nonZero+1),sizeof(int *));
    for(i=0;i<nonZero+1;i++)
        triple[i]=(int *)calloc(3,sizeof(int));
    triple[0][0]=row;
    triple[0][1]=col;
    triple[0][2]=nonZero;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(sparse[i][j])
            {
                triple[k][0]=i;
                triple[k][1]=j;
                triple[k][2]=sparse[i][j];
                k++;
            }
        }
    }
}
