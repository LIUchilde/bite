#define  _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//namespace N1
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right) {
//		return left+right;
//	}
// }
//namespace N2 {
//	int a = 30;
//	int b = 40;
//	int Add(int left, int right) {
//		return left+right;
//	}
//	namespace N3 {
//		int c = 50;
//		int d = 60;
//		int Sub(int left, int right) {
//			return left - right;
//		}
//	}
//}
//int main() {
//	using namespace N2;
//	printf("%d ", N1::a);
//	printf("%d ", a);
//	printf("%d ", N2::N3::c);
//	printf("%d ",Add(10, 20));
//	printf("%d ",N2::N3::Sub(20, 10));
//	printf("\n");
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
//int main() {
//	int a;
//	double b;
//	char c;
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c;
//	system("pause");
//	return 0;
//}
//void TestFunc(int a = 0) {
//	cout << a << endl;
//}
//int main() {
//	TestFunc();
//	TestFunc(10);
//	system("pause");
//	return 0;
//}
//void TestFunc(int a = 0, int b = 1) {
//	cout << a << " " << b << endl;
//}
//int main() {
//	TestFunc(10);
//	TestFunc(10, 20);
//	system("pause");
//	return 0;
//}
//void TestFunc(int a=1, int b) {
//	cout << a << " " << b;
//}
//int main() {
//	TestFunc();
//	system("pause");
//	return 0;
//}
//注：半缺省参数必须从右往前给出，不能间隔给；
//void TestFunc(int a = 10);
//void TestFunc(int a = 10) {
//	cout << a << endl;
//}
//int main() {
//	TestFunc(1);
//	system("pause");
//	return 0;
//}
//注：缺省参数不能在函数声明和定义中同时出现；
//如果声明和定义同时出现，恰巧两个位置提供的值不同，那编译器不知道用哪个缺省值
//void TestFunc(int a = 10);
//void TestFunc(int a) {
//	cout << a << endl;
//}
//int main() {
//	TestFunc(20);
//	system("pause");
//	return 0;
//}
void print(int i) {
	cout << i << endl ;
}
void print(string str) {
	cout << str << endl;
}
int main() {
	print(1);
	print("hello world");
	system("pause");
	return 0;
}



