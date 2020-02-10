#include<iostream>
using namespace std;
#if 0
void Add(int& left, int& right) {
	int temp = left;
	left = right;
	right = temp;
}
int main() {
	int a = 10;
	int b = 20;
	Add(a, b);
	cout << a << " " << b << endl;
	return 0;
}
#endif

#if 0
int& Add(int left, int right) {
	int sum = left + right;
	return sum;
}
int main() {
	int& ret = Add(10, 20);
	Add(20, 30);
	cout << ret << endl;
	return 0;
}
#endif

#if 0
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;//10 20
	swap(a, b);
	cout << a << " " << b << endl;//10 20
	return 0;
}
#endif

#if 0
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
int main() {
	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;//10 20
	swap(&a, &b);
	cout << a << " " << b << endl;//20 10
	return 0;
}
#endif

#if 0
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
#endif


int main() {
	return 0;
}