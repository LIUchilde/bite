#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"test.h"
int main() {
	int a[] = { 1,9,2,8,3,7,4,6,5,0 };
	int size = sizeof(a) / sizeof(a[0]);
	insertsort(a, size);
	printfArray(a, size);
	shellsort(a, size);
	printfArray(a, size);
	selectsort(a, size);
	printfArray(a, size);
	heapsort(a, size);
	printfArray(a, size);
	bubblesort(a, size);
	printfArray(a, size);
	Mergesort(a, size);
	printfArray(a, size);
	system("pause");
	return 0;
}