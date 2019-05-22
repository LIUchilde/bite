#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void reverse_string( char* str)
{
	assert(str != NULL);
	char* p=str;
	char temp;
	while (*p)
	{
		p++;
	}
	p--;
	
	while (p >= str)
	{
		temp = *str;
		*str = *p;
		*p = temp;
		str++;
		p--;
	}
	
}

int main()
{
	char arr[] = "i like it";
	reverse_string(arr);
	printf("%s", arr);
	system("pause");
	return 0;
}
 