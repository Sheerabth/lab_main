#include<stdio.h>
void main()
{
	char ch;
	printf("Enter the letter for the respective animal\n");
	tab:	printf("D for dog\nC for cat\nB for bird\nR for reptile\n");
		scanf("%c",&ch);
		switch(ch)
		{
			case 'd':
			case 'D': printf("A dog that has been neutered costs Rs.350\n");
				  printf("A dog that has not been neutered costs Rs.280\n");
				  break;
			case 'c':
        	        case 'C': printf("A cat that has been neutered costs Rs.240\n");
        	                  printf("A cat that has not been neutered costs Rs.260\n");
				  break;
 			case 'b':
        	        case 'B': printf("A bird costs nothing\n");
				  break;
 			case 'r':
        	        case 'R': printf("A reptile costs nothing\n");
				  break;
			default: printf("\nEnter any one of the animal with apropriate code\n");
				 goto tab;
	}
}
