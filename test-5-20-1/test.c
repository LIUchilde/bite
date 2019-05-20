#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[5] = { 1, 3, 5, 7, 9 };
	int b[5] = { 0, 2, 4, 6, 8 };
	int c[10];
	int i, j,temp;
	for ( i = 0; i < 5; i++)
	{
		c[i] = a[i];
	}
	for (j = 0; j < 5; j++, i++)
	{
		c[i] = b[j];
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j<9 - i; j++)
		{
			if (c[j]>c[j + 1])
			{
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", c[i]);
	}
	system("pause");
	return 0;

}
 