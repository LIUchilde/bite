#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int main()
{
	char s[] = "this is-a:student";
	char* delim = " -:";
	char* token;
	printf("%s", token =strtok(s, delim));
	while (token = strtok(NULL, delim))
	{
		printf("%s\n", token);
	}
	printf("\n");
	system("pause");
	return 0;
}