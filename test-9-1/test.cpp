#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//int Min(int a, int b) {
//	return a < b ? a : b;
//}
////����ָ�뺯��
//int(*fun)(int, int);
//int main() {
//	int i = 10;
//	int j = 20;
//	fun = &Max;//����ָ�븳ֵ
//	cout << fun(i, j) << endl;
//	fun = &Min;
//	cout << fun(i, j) << endl;
//	system("pause");
//	return 0;
//}

//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//int(*fun)(int, int);
//int getMax(int a, int b, int(*fun)(int, int)) {
//	return fun(a, b);
//}
//int main() {
//	int i = 10;
//	int j = 20;
//	cout << getMax(i, j, Max)<<endl;
//	system("pause");
//	return 0;
//}

//int add(int a, int b) {
//	return a + b;
//}
//int sub(int a, int b) {
//	return a - b;
//}
//int mul(int a, int b) {
//	return a * b;
//}
//int div(int a, int b) {
//	return a / b;
//}
//int main() {
//	int x, y;
//	int input = 0;
//	int ret=0;
//	int(*p[5])(int x, int y) = { 0,add,sub,mul,div };
//	cout << "ѡ�������0~4��" << endl;
//	cin >> input;
//	cout << "������������" << endl;
//	cin >>x>>y;
//	ret = (*p[input])(x, y);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

typedef int (*pFun)(int, int);//���庯��ָ�����
int Max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	pFun fun;                 //���庯��ָ�����
	fun = Max;                //����ָ�������ֵ
	cout << (*fun)(10, 20) << endl;
	system("pause");
	return 0;
}
