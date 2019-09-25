#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//多态的实现条件--必须在继承体系中
//>>基类中必须有虚函数，派生类必须对积累的虚函数进行重写
//>>虚函数调用：通过积累的指针或引用进行调用虚函数
//体现：在代码运行时，根据积累的指针指向不同子类的对象，调用对应子类的虚函数


//重写概念：
//>>被重写的函数在基类中必须为虚函数
//>>派生类虚函数前虚拟的关键字加不加都可以，建议加上
//>>一个在基类中，一个在派生类中
//>>派生类虚函数必须与基类虚函数的原型完全一致
//       例外：
//        a：协变：基类的虚函数返回的是基类的指针或引用
//                 派生类的虚函数返回的是派生类的指针或引用
#if 0
class person {
public:
	virtual void BuyTicket() {
		cout << "全价购票" << endl;
	}
protected:
	string _name;
	string _gender;
	string _job;
};
class student : public person {
public:
	virtual void BuyTicket() {
		cout << "半价购票" << endl;
	}
protected:
	int _stuId;
};
class soldier :public person {
public:
	virtual void BuyTicket() {
		cout << "军人优先" << endl;
	}
};
void TestBuyTicket(person& p) {
	p.BuyTicket();
}
int main() {
	person p;
	TestBuyTicket(p);
	student st;
	TestBuyTicket(st);
	soldier so;
	TestBuyTicket(so);
	return 0;
}
#endif

//如果多态的实现条件没有完全满足，全部调用的是基类的虚函数

//派生类虚函数前面没有虚拟的关键字，也构成重写
#if 0
class person {
public:
	virtual void BuyTicket() {
		cout << "全价购票" << endl;
	}
};
class student : public person {
public:
	void BuyTicket() {
		cout << "半价购票" << endl;
	}
};
class soldier : public person {
public:
	void BuyTicket() {
		cout << "军人优先" << endl;
	}
};
void TestBuyTicket(person&p) {
	p.BuyTicket();
}
int main() {
	person p;
	TestBuyTicket(p);
	student st;
	TestBuyTicket(st);
	soldier so;
	TestBuyTicket(so);
	return 0;
}
#endif

//协变
//基类和子类虚函数的返回值类型不同
#if 0
class Base {
public:
	virtual Base* TestFunc() {
		cout << "Base:TestFunc" << endl;
		return this;
	}
};
class Derived : public Base {
public:
	virtual Derived* TestFunc() {
		cout << "Derived::TestFunc" << endl;
		return this;
	}
};
void Test(Base*b) {
	b->TestFunc();
}
int main() {
	Base b;
	Test(&b);
	Derived d;
	Test(&d);
	return 0;
}
#endif

#if 0
class A
{};
class B : public A 
{};
A a;
B b;

class Base {
public:
	virtual A& TestFunc() {
		cout << "A:TestFunc" << endl;
		return a;
	}
};
class Derived : public Base {
	virtual B& TestFunc() {
		cout << "B:TestFunc" << endl;
		return b;
	}
};
void Test(Base* pb) {
	pb->TestFunc();
}
int main() {
	Base ba;
	Test(&ba);
	Derived d;
	Test(&d);
	return 0;
}
#endif

//析构函数--只要基类中的析构函数是虚函数，派生类的析构函数一旦
//提供，便会与基类的析构函数构成重写
#if 0
class Base {
public:
	virtual ~Base() {
		cout << "Base::~Base()" << endl;
	}
protected:
	int _b;
};
class Derived :public Base {
public:
	Derived() {
		_d = new int[10];
	}
	~Derived() {
		if (_d) {
			delete[]_d;
		}
		cout << "Derived::~Derived()" << endl;
	}
protected:
	int *_d;
};
int main() {
	Base* pb = new Derived;
	delete pb;
	return 0;
}
#endif

#if 0
class Base {
public:
	virtual void TestFunc1()  {
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3() {
		cout << "Base::TestFunc3()" << endl;
	}
};
class Derived :public Base {
public:
	virtual void TestFunc1()override {
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc2()override {
		cout << "Derived::TestFunc2()" << endl;
	}
	virtual void TestFunc3()override {
		cout << "Derived::TestFunc3()" << endl;
	}
};
void Test(Base& b) {
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}
int main() {
	Base b;
	Test(b);
	Derived d;
	Test(d);
	return 0;
}
#endif

//final修饰虚函数：表明该虚函数不能被派生类重写
class A {
public:
	virtual void TestFunc() {
		cout << "A::TestFunc()" << endl;
	}
};
class B :public A {
public:
	virtual void TestFunc()final {
		cout << "B::TestFunc()" << endl;
	}
};
class C :public B {
public:
	virtual void TestFunc() {
		cout << "C::TestFunc()" << endl;
	}
};
void Test(A& a) {
	a.TestFunc();
}
int main() {
	A a;
	Test(a);
	B b;
	Test(b);
	C c;
	Test(c);
	return 0;
}




