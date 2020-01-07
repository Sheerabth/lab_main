#include<iostream>
using namespace std;

class Sum
{
    public:
        int merge(int ,int);
        float merge(float, float);
        char merge(char, char);
        int *merge(int *,int *,int);
        float *merge(float *,float *,int);
        char *merge(char *,char *,int);
};

int Sum::merge(int x,int y)
{
    return x+y;
}

float Sum::merge(float x,float y)
{
    return x+y;
}

char Sum::merge(char x,char y)
{
    return x+y;
}

int* Sum::merge(int *x,int *y,int len)
{
    int *sum=new int[len];
    for(int i=0;i<len;i++)
        sum[i]=x[i]+y[i];
    return sum;
}

float* Sum::merge(float *x,float *y,int len)
{
    float *sum=new float[len];
    for(int i=0;i<len;i++)
        sum[i]=x[i]+y[i];
    return sum;
}

char* Sum::merge(char *x,char *y,int len)
{
    char *sum=new char[len];
    for(int i=0;i<len;i++)
        sum[i]=x[i]+y[i];
    return sum;
}