#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 1024

void sort(int a[], int b[],int c[], int num1, int num2){
	
	int i = 0;
	int j = 0;
	while (i < num1&&j < num2){
		if (a[i] < b[j]){
			c[i + j] = a[i];
			i++;
			continue;
		}
		c[i+j]= b[j];
		j++;
	}
	while (i < num1){
		c[i + j] = a[i];
		i++;
	}
	while (j < num2)
	{
		c[i + j] = b[j];
		j++;
	}
}
int main()
{
	int a[] = { 1, 3, 5, 7, 9 };
	int b[] = { 2, 4, 6, 8, 10 };
	int c[N];
	int sz1 = sizeof(a) / sizeof(a[0]);
	int sz2 = sizeof(b) / sizeof(b[0]);
	int n = sz1 + sz2;
	sort(a, b, c,sz1,sz2);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}