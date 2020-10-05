#include "sparseMatrix.h"
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
        if(triple[i][0]==s.triple[j][0]&&triple[i][1]==s.triple[j][1])
        {                                                                               
            sum.triple[k][0]=triple[i][0];
            sum.triple[k][1]=triple[i][1];
            sum.triple[k][2]=triple[i][2]+s.triple[j][2];
            i++;
            j++;
        }
        else if(triple[i][1]<s.triple[j][1]||triple[i][0]<s.triple[j][0])
        {
            sum.triple[k][0]=triple[i][0];
            sum.triple[k][1]=triple[i][1];
            sum.triple[k][2]=triple[i][2];
            i++;
        }
        else
        {
            sum.triple[k][0]=s.triple[j][0];
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
    sum.nonZero=k-1;
    sum.triple[0][2]=sum.nonZero;
    return sum;
}

int main()
{
    sparseMatrix s1,s2,sum;
    cout<<"Enter the details of first matrix:\n";
    s1.read();
    cout<<"Enter the details of second matrix\n";
    s2.read();
    s1.findTripleRep();
    s2.findTripleRep();
    cout<<"Triple representation of first matrix is:\n";
    s1.displayTriple();
    cout<<"Triple representation of second matrix is:\n";
    s2.displayTriple();
    sum=s1.addMatrix(s2);
    cout<<"The sum of both the matrices in triple representation is:\n";
    sum.displayTriple();
}