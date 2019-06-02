#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void reservestence(char* str, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
	return 0;
}
void reserveword(char* str)
{
	char* i;
	char* j;
	char* k=0;
	j = str;
	while (*j != '\0')
	{
		i = j;
		while (*j != ' ' && *j != '\0')
		{
			j++;
		}
		k =j - 1;
		reservestence(str, (int)(i-str), (int)(k-str));
		j++;
	}
	return;
}
int main()
{
	char str[] = "i am a student";
	int len = sizeof(str) / sizeof(char);
	reserveword(str);
	reservestence(str, 0, len - 1);
	printf("%s\n", str);
	system("pause");
	return 0;
}