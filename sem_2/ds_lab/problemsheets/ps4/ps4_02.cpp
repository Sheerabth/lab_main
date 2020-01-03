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
        sparseMatrix addMatrix(sparseMatrix);
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

sparseMatrix sparseMatrix::addMatrix(sparseMatrix s)
{
    sparseMatrix sum;
    int i,j,k=1;
    sum.nonZero=nonZero+s.nonZero;
    sum.triple=(int **)calloc((sum.nonZero+1),sizeof(int *));
    for(i=0;i<sum.nonZero+1;i++)
        sum.triple[i]=(int *)calloc(3,sizeof(int));
    sum.triple[0][0]=row;
    sum.triple[0][1]=col;
    for(i=1,j=1;i<nonZero+1&&j<s.nonZero+1;)
    {
        sum.triple[k][0]=triple[i][0];
        if(triple[i][0]==s.triple[j][0])
        {
            sum.triple[k][1]=triple[i][1];
            sum.triple[k][2]=triple[i][2]+s.triple[j][2];
            i++;
            j++;
        }
        else if(triple[i][1]<s.triple[j][1]||triple[i][0]<s.triple[j][0])
        {
            sum.triple[k][1]=triple[i][1];
            sum.triple[k][2]=triple[i][2];
            i++;
        }
        else
        {
            sum.triple[k][1]=s.triple[j][1];
            sum.triple[k][2]=s.triple[j][2];
            j++;
        }
        k++;
    }
    while(i<nonZero+1)
    {
        sum.triple[k][0]=triple[i][0];
        sum.triple[k][1]=triple[i][1];
        sum.triple[k][2]=triple[i][2];
        i++;
        k++;
    }
    while(j<s.nonZero+1)
    {
        sum.triple[k][0]=s.triple[j][0];
        sum.triple[k][1]=s.triple[j][1];
        sum.triple[k][2]=s.triple[j][2];
        j++;
        k++;
    }
    for(i=k;i<sum.nonZero+1;i++)
        free(sum.triple[i]);
    sum.triple=(int **)realloc(sum.triple,k*sizeof(int *));
    sum.nonZero=k;
    return sum;
}

int main()
{
    sparseMatrix s1,s2,sum;
    s1.read();
    s2.read();
    s1.displaySparse();
    s2.displaySparse();
    s1.findTripleRep();
    s2.findTripleRep();
    s1.displayTriple();
    s2.displayTriple();
    sum=s1.addMatrix(s2);
    sum.displayTriple();
}