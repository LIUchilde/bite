#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int j = 0;
	for (i = 2; i < 100; i++)
	{
		for (j = 2; j < i;)
		{
			if (i%j == 0)
				break;
			else
			{
				j++;
			}
		}
			if (i == j)
			{
				printf("%d ",i);
			}	
	}
	system("pause");
	return 0;
}
 