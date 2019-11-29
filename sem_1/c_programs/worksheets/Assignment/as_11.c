#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
	long int id;
	char name[20];
	float quiz,lab,exam;
};
struct score
{
	long int id;
	char name[20];
	float score;
};
void read(struct student *s)
{
	printf("\n");
	printf("ID: ");
	scanf("%ld",&s->id);
	printf("Name: ");
	scanf("%s",s->name);
	printf("Quiz score: ");
	scanf("%f",&s->quiz);
	printf("Lab score: ");
	scanf("%f",&s->lab);
	printf("Exam score: ");
	scanf("%f",&s->exam);
	printf("\n");
}
void display1(struct student s)
{
	printf("\n");
	printf("ID: %ld\n",s.id);
	printf("Name: %s\n",s.name);
	printf("Quiz score: %.1f\n",s.quiz);
	printf("Lab score: %.1f\n",s.lab);
	printf("Exam score: %.1f\n",s.exam);
	printf("\n");
}
void display2(struct score s)
{
	printf("\n");
	printf("ID: %ld\n",s.id);
	printf("Name: %s\n",s.name);
	printf("Score: %.1f\n",s.score);
	printf("\n");
}
void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Enter valid arguments\n");
		exit(0);
	}
	int i,n;
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"w+");
	printf("Enter the number of students: ");
	scanf("%d",&n);
	struct student stu;
	for(i=0;i<n;i++)
	{
		printf("Enter details of student %d\n",i+1);
		read(&stu);
		fwrite(&stu,sizeof(struct student),1,fp1);
	}
	rewind(fp1);
	struct student s1;
	struct score s2;
	fp2=fopen(argv[2],"w+");
	while(!feof(fp1))
	{
		fread(&s1,sizeof(struct student),1,fp1);
		strcpy(s2.name,s1.name);
		s2.id=s1.id;
		s2.score=s1.quiz+s1.lab+s1.exam;
		fwrite(&s2,sizeof(struct score),1,fp2);
	}
	rewind(fp1);
	rewind(fp2);
	printf("Contents of file %s\n",argv[1]);
	for(i=0;i<n;i++)
	{
		fread(&s1,sizeof(struct student),1,fp1);
		display1(s1);
	}
	printf("Contents of file %s\n",argv[2]);
	for(i=0;i<n;i++)
	{
		fread(&s2,sizeof(struct score),1,fp2);
		display2(s2);
	}
	fclose(fp1);
	fclose(fp2);
}