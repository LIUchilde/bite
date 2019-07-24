#define  _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//inline int Add(int a, int b) {
//	return a + b;
//}
//int main() {
//	printf("%d ", Add(1, 2));
//	system("pause");
//	return 0;
//}
//inline int Max(int a, int b) {
//	return a > b ? a : b;
//}
//int main() {
//	printf("%d ", Max(1, 2));
//	printf("\n");
//	system("pause");
//	return 0;
//}
//struct student {
//	void setstudentInfo(const char* name, const char* gender, int age) {
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void printstudentInfo() {
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	char _name[20];
//	char _gender[5];
//	int _age;
//};
//int main() {
//	student S;
//	S.setstudentInfo("张三", "男", 16);
//	S.printstudentInfo();
//	S.setstudentInfo("王五", "男", 18);
//	S.printstudentInfo();
//	system("pause");
//	return 0;
//}
//class person {
//public:
//	void setpersonInfo(const char* name, const char* gender, int age) {
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void printpersoninfo() {
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//private:
//	char _name[20];
//	char _gender[5];
//	int _age;
//};
//int main() {
//	person P;
//	P.setpersonInfo("张三", "男", 16);
//	P.printpersoninfo();
//	P.setpersonInfo("倩倩", "女", 15);
//	P.printpersoninfo();
//	system("pause");
//	return 0;
//}
//class point {
//public:
//	void setpoint(int x, int y){
//		xpos = x;
//		ypos = y;
//	}
//	void printpoint(){
//		cout <<"("<<xpos<<", "<<ypos <<")"<< endl;
//	}
//private:
//	int xpos;
//	int ypos;
//};
//int main() {
//	point p;
//	p.setpoint(1, 2);
//	p.printpoint();
//	system("pause");
//	return 0;
//}
//#include"person.h"
//
//void person::setpersonInfo(const char* name, const char* gender, int age) {
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//void person::printpersonInfo() {
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//int main() {
//	person P;
//	P.setpersonInfo("张三", "男", 15);
//	P.printpersonInfo();
//	P.setpersonInfo("莉莉", "女", 14);
//	P.printpersonInfo();
//	system("pause");
//	return 0;
//}
//#include<iostream>
//namespace N1 {
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right) {
//		return left + right;
//	}
//}
//namespace N2 {
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right) {
//		return left + right;
//	}
//	namespace N3 {
//		int c = 30;
//		int d = 40;
//		int Sub(int left, int right) {
//			return left - right;
//		}
//	}
//}
//int main() {
//	using namespace N2;
//		printf("%d ", N1::a);
//		printf("%d ", b);
//		printf("%d ", N2::N3::c);
//		printf("%d ", Add(10, 20));
//		printf("%d ", N2::N3::Sub(30, 20));
//		system("pause");
//		return 0;
//}
//#include<iostream>
//using namespace std;
//int main() {
//	int a;
//	char b;
//	double c;
//	cin >> a >> b >> c;
//	cout << a << " " << b << " " << c << endl;
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void TestFunc(int a = 10) {
//	cout << a << endl;
//}
//int main() {
//	TestFunc();
//	TestFunc(20);
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void TestFunc(int a, int b = 10) {
//	cout << a <<" "<< b << endl;
//}
//int main() {
//	TestFunc(20);
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void print(int i) {
//	cout << i << endl;
//}
//void print(string str) {
//	cout << str << endl;
//}
//int main() {
//	print(1);
//	print("hello world");
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void TestFunc() {
//	int a = 10;
//	int& ra = a;
//	ra = 100;
//	cout << a << " " << ra << endl;//100  100
//}
//int main() {
//	TestFunc();
//	system("pause");
//	return 0;
//}


