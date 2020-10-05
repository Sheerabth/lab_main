#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("sleep");
    usleep(10);
    printf("hello");
    return 0;
}