#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void ret(char* str)
{
	if (*str != '\0')
	{

		str++;
		ret(str);
		printf("%c", *(str-1));
    }
}

int main()
{
	char str[10] = "0";
	printf("���ӡһ���ַ�\n");
	scanf("%s", str);
	ret(str);
	system("pause");
	return 0;
}
 