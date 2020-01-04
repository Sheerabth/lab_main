#include "sparseMatrix.h"
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
    cout<<"Enter the details of the sparse matrix:\n";
    s.read();
    s.findTripleRep();
    cout<<"Its triple representation is:\n";
    s.displayTriple();
    tran=s.transpose();
    cout<<"Its transpose is:\n";
    tran.displaySparse();
    tripleTran=s.tripleTranspose();
    cout<<"Its transpose in triple repesentation is:\n";
    tripleTran.displayTriple();
}