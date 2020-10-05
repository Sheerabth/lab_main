#include "sparseMatrix.h"

bool sparseMatrix::ifTwin(sparseMatrix s)
{
    int i;
    if(nonZero==s.nonZero)
    {
        for(i=0;i<nonZero+1;i++)
        {
            if(triple[i][0]!=s.triple[i][0])
                return 0;
        }
        return 1;
    }
    return 0;
}

sparseMatrix sparseMatrix::result(sparseMatrix s)
{
    int i,j;
    sparseMatrix result;
    result.nonZero=nonZero;
    result.triple=(int **)calloc((result.nonZero+1),sizeof(int *));
    for(i=0;i<nonZero+1;i++)
        result.triple[i]=(int *)calloc(3,sizeof(int));
    for(i=0;i<nonZero+1;i++)
        for(j=0;j<3;j++)
            result.triple[i][j]=triple[i][j];
    for(i=1;i<nonZero+1;i++)
    {
        if(triple[i][2]==s.triple[i][2])
            result.triple[i][2]=1;
        else if(triple[i][2]>s.triple[i][2])
            result.triple[i][2]=2;
        else
            result.triple[i][2]=-2;
    }
    return result;   
}

int main()
{
    bool areTwins;
    sparseMatrix s1,s2,resultTriple;
    cout<<"Enter details of 1st matrix:\n";
    s1.read();
    cout<<"Enter details of 2nd matrix:\n";
    s2.read();
    s1.findTripleRep();
    s2.findTripleRep();
    if(s1.ifTwin(s2))
    {
        cout<<"The matrices are twin matrices\n";
        resultTriple=s1.result(s2);
        cout<<"The manipulated sum of the matrices is:\n";
        resultTriple.displayTriple();
    }
    else
        cout<<"The matrices are not twin matrices\n";
}


















