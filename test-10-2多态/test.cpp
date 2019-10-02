#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
class B1 {
public:
	virtual void TestFunc1() {
		cout << "B1::TestFunc()" << endl;
	}
	virtual void TestFuunc2() {
		cout << "B1::TestFunc2()" << endl;
	}
	int _b1;
};
class B2 {
public:
	virtual void TestFunc3() {
		cout << "B2::TestFunc3()" << endl;
	}
	virtual void TestFunc4() {
		cout << "B2::TestFunc4()" << endl;
	}
	int _b2;
};
class D :public B1, public B2 {
public:
	virtual void TestFunc1() {
		cout << "D::TestFunc1()" << endl;
	}
	virtual void TestFunc3() {
		cout << "D::TestFunc3()" << endl;
	}
	virtual void TestFunc5() {
		cout << "D::TestFunc5()" << endl;
	}
	int _d;
};
typedef void(*PVF)();
void printVFT(B1&b,string str) {
	cout << str << endl;
	PVF* pVF = (PVF*) * (int*)(&b);
	while (*pVF) {
		(*pVF)();
		pVF++;
	}
	cout << endl;
}
void printVFT(B2& b, string str) {
	cout << str << endl;
	PVF* pVF = (PVF*) * (int*)(&b);
	while (*pVF) {
		(*pVF)();
		pVF++;
	}
	cout << endl;
}
int main() {
	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	B1& b1 = d;
	printVFT(b1, "B1 VFT:");
	B2& b2 = d;
	printVFT(b2, "B2 VFT:");
	return 0;
}
#endif

#if 0
class B {
public:
	virtual void TestFunc1() {
		cout << "B::TestFunc1()" << endl;
	}
	virtual void TestFunc2() {
		cout << "B::TestFunc2()" << endl;
	}
	int _b;
};
class C1:public B {
public:
	virtual void TestFunc1() {
		cout << "C1::TestFunc1()" << endl;
	}
	virtual void TestFunc3() {
		cout << "C1::TestFunc3()" << endl;
	}
	int _c1;
};
class C2: public B {
public:
	virtual void TestFunc2() {
		cout << "C2::TestFunc2()" << endl;
	}
	virtual void TestFunc4() {
		cout << "C2::TestFunc4()" << endl;
	}
	int _c2;
};
class D:public C1,public C2 {
public:
	virtual void TestFunc3() {
		cout << "D::TestFun3()" << endl;
	}
	virtual void TestFunc4() {
		cout << "D::TestFunc4()" << endl;
	}
	virtual void TestFunc5() {
		cout << "D::TestFunc5()" << endl;
	}
	int _d;
};
typedef void (*PVF)();
void printVFT(C1& c, string str) {
	cout << str << endl;
	PVF* pVF = (PVF*) * (int*)(&c);
	while (*pVF) {
		(*pVF)();
		pVF++;
	}
	cout << endl;
}
void printVFT(C2& c, string str) {
	cout << str << endl;
	PVF* pVF = (PVF*) * (int*)(&c);
	while (*pVF) {
		(*pVF)();
		pVF++;
	}
	cout << endl;
}
int main() {
	D d;
	d._c1 = 1;
	d._c2 = 2;
	d._d = 3;
	C1& c1 = d;
	printVFT(c1, "VFT C1:");
	C2& c2 = d;
	printVFT(c2, "VFT C2:");
	return 0;
}
#endif

class A {
public:
	virtual ~A() {
		cout << "A::~A()" << endl;
	}
};
class B :public A {
public:
	B() {
		cout << "B::B()" << endl;
		p = new int[10];
	}
	~B() {
		cout << "B::~B()" << endl;
		delete[]p;
	}
protected:
	int* p;
};
int main() {
	A* pa = new B;
	delete pa;
	return 0;
}


