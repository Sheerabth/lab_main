#include<stdio.h>
#include<limits.h>
#include<float.h>
void main()
{
        printf("NAME \t\t\t\t SIZE \t\t\t\t MINIMUM VALUE \t\t\t\t MAXIMUM VALUE\n");
        printf("Int \t\t\t\t %ld \t\t\t\t %d \t\t\t\t %ld\n",sizeof(int),INT_MIN,INT_MAX);
        printf("Short \t\t\t\t %ld \t\t\t\t %hi \t\t\t\t %ld\n",sizeof(short),SHRT_MIN,SHRT_MAX);
        printf("Unsigned Short \t\t\t %ld \t\t\t\t %ld \t\t\t\t\t %ld\n",sizeof(unsigned short),0,USHRT_MAX);
        printf("Unsigned Int \t\t\t %ld \t\t\t\t %ld \t\t\t\t\t %ld\n",sizeof(unsigned int),0,UINT_MAX);
        printf("Long \t\t\t\t %ld \t\t\t\t %ld \t\t\t %ld\n",sizeof(long),LONG_MIN,LONG_MAX);
        printf("Unsigned Long \t\t\t %ld \t\t\t\t %ld \t\t\t\t\t %lu\n",sizeof(unsigned long),0,ULONG_MAX);
        printf("Long Long \t\t\t %ld \t\t\t\t %ld \t\t\t %ld\n",sizeof(long long),LLONG_MIN,LLONG_MAX);
        printf("Unsigned Long Long \t\t %ld \t\t\t\t %ld \t\t\t\t\t %llu\n",sizeof(unsigned long long),0,ULLONG_MAX);
        printf("Float \t\t\t\t %ld \t\t\t\t %f \t\t\t %ld\n",sizeof(float),FLT_MIN,FLT_MAX);
        printf("Double \t\t\t\t %ld \t\t\t\t %f \t\t\t %ld\n",sizeof(double),DBL_MIN,DBL_MAX);
        printf("Long Double \t\t\t %ld \t\t\t\t %d \t\t\t %ld\n",sizeof(long double),LDBL_MIN,LDBL_MAX);
        printf("Char \t\t\t\t %ld \t\t\t\t %ld \t\t\t\t %ld\n",sizeof(char),CHAR_MIN,CHAR_MAX);
        printf("Signed Char \t\t\t %ld \t\t\t\t %ld \t\t\t\t %ld\n",sizeof(signed char),SCHAR_MIN,SCHAR_MAX);
        printf("Unsigned Char \t\t\t %ld \t\t\t\t %ld \t\t\t\t\t %ld\n",sizeof(unsigned char),0,UCHAR_MAX);
}

