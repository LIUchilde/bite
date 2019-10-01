#define  _CRT_SECURE_NO_WARNINGS 1
//继承--不同继承方式下派生类的对象模型
//单继承--一个类具有一个基类
//多继承--一个类具有多个基类

//偏移量问题

#if 0
#include<iostream>
using namespace std;
class Base1 {
public:
	int _b1;
};
class Base2 {
public:
	int _b2;
};
class Derived :public Base1, public Base2 {
public:
	int _d;
};
int main() {
	Derived d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derived* p3 = &d;
	//p1==p3!=p2
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;
class person {
public:
	virtual void BuyTicket() {
		cout << "全价购票" << endl;
	}
protected:
	string _name;
	string _dender;
	int _age;
};
class student:public person {
public:
	virtual void BuyTicket() {
		cout << "半价购票" << endl;
	}
};
void Test(person&p){
	p.BuyTicket();
}
int main() {
	person p;
	Test(p);
	student s;
	Test(s);
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
class A 
{};
class B:public A
{};
A a;
B b;
class person {
public:
	virtual A& BuyTicket() {
		cout << "全价购票" << endl;
		return a;
	}
};
class student :public person {
public:
	virtual B& BuyTicket() {
		cout << "半价购票" << endl;
		return b;
	}
};
void Test(person& p) {
	p.BuyTicket();
}
int main() {
	person p;
	student s;
	Test(p);
	Test(s);
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
class person {
public:
	virtual ~person() {
		cout << "person::~person" << endl;
	}
};
class student :public person {
public:
	virtual ~student() {
		cout << "student::~student" << endl;
	}
};
int main() {
	person* p1 = new person;
	delete p1;
	p1 = new student;
	delete p1;
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
class person {
public:
	virtual void TestFunc() {
		cout << "person::TestFunc()" << endl;
	}
};
class student:public person{
	virtual void TestFunc()override {
		cout << "student::TestFunc()" << endl;
	}
};
void Test(person&p) {
	p.TestFunc();
}
int main() {
	person p;
	student s;
	Test(p);
	Test(s);
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
class person {
public:
	virtual void TestFunc()final {
		cout << "person::TestFunc()" << endl;
	}
};
class student :public person {
	virtual void TestFunc() {
		cout << "student::TestFunc()" << endl;
	}
};
void Test(person& p) {
	p.TestFunc();
}
int main() {
	person p;
	student s;
	Test(p);
	Test(s);
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
const double PI = 3.14159;
class shape {
public:
	virtual void disp() = 0;
	void setvalue(int x, int y=0) {
		_x = x;
		_y = y;
	}
protected:
	int _x;
	int _y;
};
class Square :public shape {
public:
	virtual void disp() {
		cout << "矩形面积："<<_x * _y << endl;
	}
};
class Circle :public shape {
public:
	virtual void disp() {
		cout << "圆面积" << PI * _x * _x << endl;
	}
};
void Test() {
	shape* s = nullptr;
	Square sq;
	Circle c;
	s = &sq;
	s->setvalue(2, 4);
	s->disp();
	s = &c;
	s->setvalue(10);
	s->disp();
}
int main() {
	Test();
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
class Base {
public:
	virtual void TestFunc1() {
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3() {
		cout << "Base::TestFunc3()" << endl;
	}
protected:
	int _b;
};
class Derived :public Base {
public:
	virtual void TestFunc5() {
		cout << "Derived::TestFunc5()" << endl;
	}
	virtual void TestFunc1() {
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc3() {
		cout << "Derived::TestFunc3()" << endl;
	}
	virtual void TestFunc4() {
		cout << "Derived::TestFunc4()" << endl;
	}
protected:
	int _d;
};
typedef void(*PVF)();
void printVFT(Base& b, string str) {
	cout << str << endl;
	//1.从对象前4个字节取虚表的地址
	PVF* pVF = (PVF*) * (int*)& b;
	while (*pVF) {
		(*pVF)();
		pVF++;
	}
	cout << endl;
}
int main() {
	Base b;
	Derived d;
	printVFT(d, "Derived VFT");
	return 0;
}
#endif

#include<iostream>
using namespace std;
class Base {
public:
	virtual void TestFunc1() {
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3() {
		cout << "Base::TestFunc3()" << endl;
	}
protected:
	int _b;
};
class Derived :public Base {
public:
	virtual void TestFunc5() {
		cout << "Derived::TestFunc5()" << endl;
	}
	virtual void TestFunc1() {
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc3() {
		cout << "Derived::TestFunc3()" << endl;
	}
	virtual void TestFunc4() {
		cout << "Derived::TestFunc4()" << endl;
	}
protected:
	int _d;
};
void Test(Base& b) {
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}
int main() {
	Base b;
	Derived d;
	Test(b);
	Test(d);
	return 0;
}
