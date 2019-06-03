#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 100
int n;
int P[N][N], Q[N][N];
int x[N];
int opt[N];
int tempValue = 0, maxValue = 0;
void compute() 
{
	tempValue = 0;
	for (int i = 1;i <= n;i++) 
	{
    	tempValue += P[i][x[i]] * Q[x[i]][i];
	}
	if (tempValue > maxValue)
	{
		maxValue = tempValue;
		for (int i = 1;i <= n;i++)
		{
			opt[i] = x[i];
    	}
	}
}
void traceback(int t)
{
	int i, j, temp;
	if (t > n)
	{
		compute();
	}
	for (i = t;i <= n;i++)
	{
		temp = x[i];
		x[i] = x[t];
		x[t] = temp;
		traceback(t + 1);
		temp = x[i];
		x[i] = x[t];
		x[t] = temp;
	}
}
int main()
{
	int n=scanf("%d", &n);
	for (int i = 1;i <= n;i++)
	{
		x[i] = i;
	}
	for (int i = 1;i <= n;i++)
	{
	for (int j = 1;j <= n;j++)
	{
			int n=scanf("%d", &P[i][j]);
		}
	}
	for (int i = 1;i <= n;i++) 
	{
		for (int j = 1;j <= n;j++) 
		{
			int n=scanf("%d", &Q[i][j]);
		}
	}
	traceback(1);
	printf("%d\n", maxValue);
	for (int i = 1;i <= n;i++) 
	{
		printf("%d------%d\n", i, opt[i]);
	}
	return 0;
}
