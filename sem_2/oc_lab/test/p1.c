#include<stdio.h>
#include<stdlib.h>
struct student
{
        char name[20];
        int age;
        float height,weight;
};
void read(struct student *s)
{
        printf("Enter the name: ");
        scanf("%*c%[^\n]s",s->name);
        printf("Enter the age: ");
        scanf("%d",&s->age);
        printf("Enter the height(in cm): ");
        scanf("%f",&s->height);
        printf("Enter the weight(in kg): ");
        scanf("%f",&s->weight);
}
void display(struct student s)
{
        printf("The name of student is %s\n",s.name);
        printf("The age of student is %d\n",s.age);
        printf("The height of student is %.1fcm\n",s.height);
        printf("The weight of student is %.1fkg\n",s.weight);
}
void displaytable(struct student *s,int n)
{
        int i;
        printf("\n\n\t\tName\tAge\tHeight(in cm)\tWeight(in kg)\n\n");
        for(i=0;i<n;i++)
                printf("%20s\t%d\t%.1f\t\t%.1f\n",s[i].name,s[i].age,s[i].height,s[i].weight);
        printf("\n\n");
}
struct student maxheight(struct student *s,int n)
{
        int i,max=0,mem;
        for(i=0;i<n;i++)
        {
                if(s[i].height>max)
                {
                        max=s[i].height;
                        mem=i;
                }
        }
        return s[mem];
}
void main()
{
        int i,n;
        printf("Enter the number of student data: ");
        scanf("%d",&n);
        struct student smax;
        struct student *s=(struct student *)malloc(n*sizeof(struct student));
        for(i=0;i<n;i++)
        {
                printf("Enter the details of student %d\n",i+1);
                read(&s[i]);
        }
        printf("The details of all the students are\n");
        displaytable(s,n);
        smax=maxheight(s,n);
        printf("The details of student with maximum height is\n");
        display(smax);
}
