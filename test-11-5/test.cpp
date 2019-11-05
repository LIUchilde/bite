#include<iostream>
using namespace std;
#if 0
class person {
public:
	virtual void BuyTick() {
		cout << "全价购票" << endl;
	}
private:
	string _name;
	string _dener;
	int _age;
};
class student :public person {
public:
	virtual void BuyTick() {
		cout << "半价购票" << endl;
	}
};
void Test(person& p) {
	p.BuyTick();
}
int main() {
	person p;
	Test(p);
	student stu;
	Test(stu);
	return 0;
}
#endif

#if 0
class A
{};
class B:public A
{};
A a;
B b;
class person {
public:
	virtual A& BuyTick() {
		cout << "全价购票" << endl;
		return a;
	}
};
class student :public person {
public:
	virtual B& BuyTick() {
		cout << "半价购票" << endl;
		return b;
	}
};
void Test(person&p) {
	p.BuyTick();
}
int main() {
	person p;
	Test(p);
	student stu;
	Test(stu);
	return 0;
}
#endif
#if 0
class person {
public:
	virtual ~person() {
		cout << "person::~person" << endl;
	}
};
class student :public person {
public:
	virtual ~student(){
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
class person {
public:
	virtual void TestFunc() {
		cout << "person::TestFunc" << endl;
	}
};
class student :public person {
public:
	virtual void TestFunc1() override{
		cout << "student::TestFunc" << endl;
	}
};
void Test(person& p) {
	p.TestFunc();
}
int main() {
	person p;
	Test(p);
	student stu;
	Test(stu);
	return 0;
}
#endif
#if 0
class person {
public:
	virtual void TestFunc()final {
		cout << "person::TestFunc" << endl;
	}
};
class student :public person {
public:
	virtual void TestFunc() {
		cout << "student::TestFunc" << endl;
	}
};
void Test(person& p) {
	p.TestFunc();
}
int main() {
	person p;
	Test(p);
	student stu;
	Test(stu);
	return 0;
}
#endif
#if 0
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
		cout << "矩形面积：" << _x * _y << endl;
	}
};
class Circle :public shape {
public:
	virtual void disp() {
		cout << "圆面积:" << PI * _x * _x << endl;
	}
};
void Test() {
	shape* s = nullptr;
	Square sq;
	s = &sq;
	s->setvalue(2, 4);
	s->disp();
	Circle c;
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
class Base {
public:
	virtual void TestFunc1() {
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::Testfunc2()" << endl;
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
		cout << "Derived::Testfunc5()" << endl;
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
	PVF* pVF = (PVF*) * (int*)&b;
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

class A {
public:
	virtual ~A() {
		cout << "A::~A()" << endl;
	}
};
class B :public A{
public:
	B() {
		cout << "B::B()" << endl;
		p = new int[10];
	}
	~B() {
		cout << "B:~B()" << endl;
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