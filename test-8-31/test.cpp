#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"test.h"
using namespace std;
//int feibonacci(int n) {
//	if (n == 0) {
//		return 0;
//	}
//	if (n == 1) {
//		return 1;
//	}
//	else {
//		return feibonacci(n - 1) + feibonacci(n - 2);
//	}
//}

//int feibonacci(int n) {
//	if (n == 0) {
//		return 0;
//	}
//	if (n<=2) {
//		return 1;
//	}
//	else {
//		int num1 = 1;
//		int num2 = 1;
//		for (int i = 2;i < n - 1;i++) {
//			num2 = num1 + num2;
//			num1 = num2 - num1;
//		}
//		return num1 + num2;
//	}
//}

//void reOrderArray(int a[],int n) {
//	if (a == NULL||n<=1) {
//		return;
//	}
//	int* temp;
//	temp = new int[n];
//	int m=0;
//	for (int i = 0;i < n;i++) {
//		if (a[i] % 2 == 0) {
//			m++;
//		}
//	}
//	int x = 0;
//	int y = m;
//	for (int i = 0;i < n;i++) {
//		if (a[i] % 2 == 0) {
//			temp[x++] = a[i];
//		}
//		else {
//			temp[y++] = a[i];
//		}
//	}
//	for (int i = 0;i < n;i++) {
//		a[i] = temp[i];
//	}
//}

//void reOrderArray(int a[], int n) {
//	if (a == NULL || n <= 1) {
//		return;
//	}
//	for (int i = 0;i < n;i++) {
//		for (int j = 0;j < n - i - 1;j++) {
//			if (a[j] % 2 == 0 && a[j + 1] % 2 == 1) {
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//}

//bool find(int a[3][3], int row, int col,int k, int& px, int& py) {
//	int i = 0;
//	int j = col - 1;
//	while (i < row && j >= 0) {
//		px = -1;
//		py = -1;
//		if (a[i][j] == k) {
//			px = i;
//			py = j;
//			return true;
//		}
//		if (a[i][j] < k) {
//			j--;
//		}
//		else {
//			i++;
//		}
//	}
//	return false;
//}


//int main() {
//	int a = 1;
//	int b = 2;
//	int* p[2];
//	p[0] = &a;
//	p[1] = &b;
//	printf("%p\n", p[0]);
//	printf("%p\n", &a);
//	printf("%p\n", p[1]);
//	printf("%p\n", &b);
//	printf("%d\n", *p[0]);
//	printf("%d\n", *p[1]);
//	system("pause");
//	return 0;
//}

int main() {
	/*定义一个二维数组
		0 1 2
		3 4 5
		输出第一行第二列的值：5*/
	int a[2][3] = { {0,1,2},{3,4,5} };
	int(*p)[3];//数组指针，指向含有3个元素的一维数组
	int* q[2];//指针数组，一个数组内存中存放两个指针变量
	p = a;
	q[0] = a[0];
	q[1] = a[1];
	printf("%d\n", a[1][2]);
	printf("%d\n", *(p[1] + 2));
	printf("%d\n", *(*(p + 1) + 2));
	printf("%d\n", (*(p + 1))[2]);
	printf("%d\n", p[1][2]);
	printf("%d\n", *(q[1] + 2));
	printf("%d\n", *(*(q + 1) + 2));
	printf("%d\n", *(q + 1)[2]);
	printf("%d\n", q[1][2]);
	system("pause");
	return 0;
}