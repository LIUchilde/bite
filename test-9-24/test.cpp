#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
class B {
public:
	void Test() {
		cout << "B:" << &_count << endl;
	}
	static int _count;
};
int B::_count = 0;
class D1 :public B {
public:
	void TestFunc() {
		cout << "D1:" << &_count << endl;
		_count = 10;
	}
};
class D2 :public B {
public:
	void TestFunc() {
		cout << "D2:" << &_count << endl;
		_count = 10;
	}
};
int main() {
	D1 d1;
	d1.TestFunc();
	D2 d2;
	d2.TestFunc();
	return 0;
}
#endif


#if 0
class B {
	 friend void TestFunc();
public:
protected:
	int _b;
};
class D : public B {
protected:
	int _d;
};
void TestFunc() {
	//该函数为基类的友元
	//可以在该函数中访问基类保护或者私有的成员
	B b;
	b._b = 10;

	//不能访问子类中私有或保护的成员
	D d;
	d._d = 20;

	//结论：友元关系不能被继承
	//继承：子类一定继承的是基类的成员，友元不属于基类的成员
}
int main() {
	return 0;
}
#endif


#if 0
//不同继承方式下，派生类的继承模型
//单继承  一个类只有一个基类
//多继承  一个类由多个基类
class B1 {
public:
	int _b1;
};
class B2 {
public:
	int _b2;
};
//派生类将两个积累中的成员都继承在子类中
//在对象模型中：先继承哪个基类，该基类中的成员就在对象模型的最上方
class D :public B1, public B2 {
public:
	int _d;
};
int main() {
	D d;
	cout << sizeof(d) << endl;
	d._b1 = 10;
	d._b2 = 20;
	d._d = 30;
	return 0;
}
#endif

//菱形继承  菱形继承的缺陷--菱形继承的二义性
#if 0
class B {
public:
	int _b;
};
class C1 : public B {
public:
	int _c1;
};
class C2 : public B {
public:
	int _c2;
};
class D :public C1, public C2 {
public:
	int _d;
};
int main() {
	D d;
	cout << sizeof(d) << endl;
	d.C1::_b = 10;
	d._c1 = 20;
	d.C2::_b = 30;
	d._c2 = 40;
	d._d = 50;
	return 0;
}
#endif

//让最顶层基类成员只存一份  
//菱形虚拟继承
#if 0
class B {
public:
	int _b;
};
class D :virtual public B {
public:
	int _d;
};
int main() {
	D d;
	cout << sizeof(d) << endl;
	return 0;
}
#endif


#if 0
class B {
public:
	int _b;
};
class C1 :virtual public B {
public:
	int _c1;
};
class C2 :virtual public B {
public:
	int _c2;
};
class D :public C1, public C2 {
public:
	int _d;
};
int main() {
	D d;
	d._b = 10;
	d._c1 = 20;
	d._c2 = 30;
	d._d = 40;
	cout << sizeof(d) << endl;
	return 0;
}
#endif

#if 0
class B {
public:
	B(int b)
		:_b(b)
	{}
	B(const B& b) 
		:_b(b._b)
	{}
	B& operator=(const B& b) {
		if (this != &b) {
			_b = b._b;
		}
		return *this;
	}
	~B() {
		cout << "B::~B()" << endl;
	}
protected:
	int _b;
};
class D :public B {
public:
	D(int b,int d)
		:B(b)
		,_d(d)
	{}
	D(const D& d) 
		:B(d._b)
		,_d(d._d)
	{}
	D& operator=(const D& d) {
		if (this != &d) {
			B::operator=(d);
			_d = d._d;
		}
		return *this;
	}
	~D() {
		cout << "D::~D()" << endl;
	}
protected:
	int _d;
};
int main() {
	D d(10,20);
	return 0;
}
#endif

class A final{
public:
	A(int a)
		:_a(a)
	{}
protected:
	int _a;
};
class B :public A {

};
int main() {
	B b;
	return 0;
}


