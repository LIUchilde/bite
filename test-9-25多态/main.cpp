#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//��̬��ʵ������--�����ڼ̳���ϵ��
//>>�����б������麯�������������Ի��۵��麯��������д
//>>�麯�����ã�ͨ�����۵�ָ������ý��е����麯��
//���֣��ڴ�������ʱ�����ݻ��۵�ָ��ָ��ͬ����Ķ��󣬵��ö�Ӧ������麯��


//��д���
//>>����д�ĺ����ڻ����б���Ϊ�麯��
//>>�������麯��ǰ����Ĺؼ��ּӲ��Ӷ����ԣ��������
//>>һ���ڻ����У�һ������������
//>>�������麯������������麯����ԭ����ȫһ��
//       ���⣺
//        a��Э�䣺������麯�����ص��ǻ����ָ�������
//                 ��������麯�����ص����������ָ�������
#if 0
class person {
public:
	virtual void BuyTicket() {
		cout << "ȫ�۹�Ʊ" << endl;
	}
protected:
	string _name;
	string _gender;
	string _job;
};
class student : public person {
public:
	virtual void BuyTicket() {
		cout << "��۹�Ʊ" << endl;
	}
protected:
	int _stuId;
};
class soldier :public person {
public:
	virtual void BuyTicket() {
		cout << "��������" << endl;
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

//�����̬��ʵ������û����ȫ���㣬ȫ�����õ��ǻ�����麯��

//�������麯��ǰ��û������Ĺؼ��֣�Ҳ������д
#if 0
class person {
public:
	virtual void BuyTicket() {
		cout << "ȫ�۹�Ʊ" << endl;
	}
};
class student : public person {
public:
	void BuyTicket() {
		cout << "��۹�Ʊ" << endl;
	}
};
class soldier : public person {
public:
	void BuyTicket() {
		cout << "��������" << endl;
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

//Э��
//����������麯���ķ���ֵ���Ͳ�ͬ
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

//��������--ֻҪ�����е������������麯�������������������һ��
//�ṩ�������������������������д
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

//final�����麯�����������麯�����ܱ���������д
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




