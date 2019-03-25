#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stu
{
	int score;
	char id[20];
	char *name;
	Stu()
	{
		score = 0;
		name = NULL;
		id[0] = '\0';
	}
	void setname(char *n)
	{
		name = (char*) malloc (sizeof(char) * (strlen(n) + 1) );
		strcpy(name, n);
	}
	~Stu()
	{
		free(name);
	}
};
int main()
{
	Stu lkh;
	lkh.setname("liukehong");
	printf("%s",lkh.name);
	return 0;
} 
