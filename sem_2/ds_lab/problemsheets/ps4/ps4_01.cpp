#include <iostream>
#include<stdlib.h>
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
        sparseMatrix transpose();
        sparseMatrix tripleTranspose();

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

sparseMatrix sparseMatrix::transpose()
{
    sparseMatrix spar;
    int i,j;
    spar.row=col;
    spar.col=row;
    spar.nonZero=nonZero;
    spar.sparse=(int **)calloc(spar.row,sizeof(int *));
    for(int i=0;i<row;i++)
        spar.sparse[i]=(int *)calloc(spar.col,sizeof(int));
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            spar.sparse[j][i]=sparse[i][j];
        }
    }
    return spar;
}

sparseMatrix sparseMatrix::tripleTranspose()
{

    int i,j,k=1;
    sparseMatrix tran;
    tran.nonZero=nonZero;
    tran.triple=(int **)calloc((tran.nonZero+1),sizeof(int *));
    for(i=0;i<nonZero+1;i++)
        tran.triple[i]=(int *)calloc(3,sizeof(int));
    tran.triple[0][0]=col;
    tran.triple[0][1]=row;
    tran.triple[0][2]=nonZero;
    for(i=0;i<col;i++)
    {
        for(j=1;j<tran.nonZero+1;j++)
        {
            if(triple[j][1]==i)
            {
                tran.triple[k][0]=triple[j][1];
                tran.triple[k][1]=triple[j][0];
                tran.triple[k][2]=triple[j][2];
                k++;
            }
        }
    }

    return tran;
}

int main()
{
    sparseMatrix s,tran,tripleTran;
    s.read();
    s.findTripleRep();
    s.displayTriple();
    tran=s.transpose();
    tran.displaySparse();
    tripleTran=s.tripleTranspose();
    tripleTran.displayTriple();
}