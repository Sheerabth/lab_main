#include<stdio.h>
#include<ctype.h>
void main()
{
	int i=0;
	char s[100];
	char ch[][10]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	printf("Enter the text: ");
	scanf("%[^\n]s",s);
	while(s[i]!='\0')
	{
		if(isdigit(s[i])) printf("%s ",ch[s[i]-48]);
		else if(isalpha(s[i]))
		{
			s[i]=toupper(s[i]);
			printf("%s ",ch[s[i]-55]);
		}
		else if(s[i]=='.') printf(".-.-.- ");
		else if(s[i]==',') printf("--..-- ");
		else if(s[i]=='?') printf("..--.. ");
		else if(s[i]==' ') printf("\n");
		else printf(" ");
		i++;
	}
	printf("\n");
}
