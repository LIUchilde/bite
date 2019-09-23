#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#if 0
class person {
public:
	void print() {
		cout << _name << endl;
		cout << _age << endl;
	}
private:
	string _name = "李四";
	int _age = 18;
};
class student :public person {
private:
	int _stuid;
};
class Teacher :public person {
private:
	int _jobid;
};
int main() {
	student s;
	Teacher t;
	cout << sizeof(person) << endl;//32
	cout << sizeof(s) << endl;//36
	cout << sizeof(t) << endl;//36
	s.print();
	t.print();
	return 0;
}
#endif

#if 0
class Base {
public:
	void setBaseInfo(int pub, int pro, int pri) {
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void printBaseInfo() {
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :public Base {
public:
	void setDerivedInfo(int pub, int pro, int pri) {
		//从基类继承下来的成员变量赋值
		_pub = pub;
		_pro = pro;
		//_pri = pri;//基类的private成员不能直接被使用，但它已经被继承了下来
		//子类新家的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D :public Derived {
public:
	void TestFunc(){
		_pro = 10;
	}
};
int main() {
	cout << sizeof(Derived) << endl;
	Derived d;
	d._pub = 10;
	//d._pro = 20;
	return 0;
}
#endif

#if 0
class Base {
public:
	void setBaseInfo(int pub, int pro, int pri) {
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void printBaseInfo() {
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :protected Base {
public:
	void setDerivedInfo(int pub, int pro, int pri) {
		//从基类继承下来的成员变量赋值
		//如果是保护的继承方式，基类中被public访问限定符修饰的成员变量在子类中的权限已经变为protected
		_pub = pub;
		//如果是保护的继承方式，基类中被protected访问限定符修饰的成员变量在子类中的权限不变
		_pro = pro;
		//_pri = pri;//基类的private成员不能直接被使用，但它已经被继承了下来
		//子类新家的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D : public Derived {
public:
	void TestFunc() {
		_pub = 10;
		_pro = 20;
	}
};
int main() {
	Derived d;
	d._pub = 10;
	d._pro = 20;
	return 0;
}
#endif

#if 0
class Base {
public:
	void setBaseInfo(int pub, int pro, int pri) {
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void printBaseInfo() {
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :private Base {
public:
	void setDerivedInfo(int pub, int pro, int pri) {
		//从基类继承下来的成员变量赋值
		//如果是私有的继承方式，基类中被public访问限定符修饰的成员变量在子类中的权限已经变为private
		_pub = pub;
		//如果是私有的继承方式，基类中被protected访问限定符修饰的成员变量在子类中的权限已经变为private
		_pro = pro;
		//_pri = pri;//基类的private成员不能直接被使用，但它已经被继承了下来
		//子类新家的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D : public Derived {
public:
	void TestFunc(){
		_pub = 10;
		_pro = 20;
	}

};
int main() {
	Derived d;
	d._pub = 10;
	d._pro = 20;
	return 0;
}
#endif 


#if 0
class B {
public:
	void SetB(int b) {
		_b = b;
	}
protected:
	int _b;
};
class D : public B{
public:
	void SetD(int b,int d) {
		_b = b;
		_d = d;
	}
protected:
	int _d;
};
int main() {
	B b;
	b.SetB(10);
	D d;
	d.SetD(20, 30);
	B* pb = &d;
	B& rb = d;
	return 0;
}
#endif

//同名隐藏：在基类和子类中具有相同名称的成员（成员变量，成员函数）
//          如果使用子类的对象访问继承体系中同名的成员，访问的都是子类的成员
//          基类中同名的成员永远访问不到（相当于子类同名成员将基类中同名成员隐藏）


#if 0
class Base {
public:
	Base(int b)
		:_b(b)
	{}
	Base(Base&b)
		:_b(b._b)
	{
		cout << "Base(Base&b)" << endl;
	}
	Base& operator=(const Base& b) {
		if (this != &b) {
			_b = b._b;
		}
		return *this;
	}
	~Base() {
		cout << "Base::~Base()" << endl;
	}
	int _b;
};
class Derived :public Base {
public:
	//派生类构造函数一定要在其初始化列表的位置调用基类的构造函数
	   //编译器自动调用基类默认的构造函数
	   //需要用户显式在派生类构造函数列表中进行调用
	//如果基类存在缺省的构造函数（无参或全缺省的构造函数）派生类的构造函数可以实现也可以不实现
	//如果基类显示定义的非缺省的构造函数，派生类必须在初始化列表位置显式调用基类的构造函数
	Derived(int b,int d)
		:Base(b)
		,_d(d)
	{}
	Derived(Derived&d)
		:Base(d._b)
		,_d(d._d)
	{}
	Derived& operator=(const Derived& d) {
		if (this != &d) {
			Base::operator=(d);
			_d = d._d;
		}
		return *this;
	}
	~Derived() {
		cout << "Derived::~Derived" << endl;
	}
	int _d;
};
int main() {
	Derived d1(10,20);
	Derived d2(d1);
	Derived d3(30, 40);
	d1 = d3;
	return 0;
}
#endif

#if 0
class Base {
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base::Base()" << endl;
	}
	~Base() {
		cout << "Base::~Base()" << endl;
	}
	int _b;
};
class Derived :public Base {
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{
		cout << "Derived::Derived()" << endl;
	}
	~Derived() {
		cout << "Derived::~Derived" << endl;
	}
	int _d;
};
int main() {
	Derived d(10, 20);
	//创建那个类的对象，调用那个类的构造
	//析构哪个类的对象，调用哪个类的析构
	return 0;
}
#endif

class A final{
public:
	A(int a=10)
		:_a(a)
	{}
protected:
	int _a;
};
class B :public A {

};
int main() {
	A a;
	return 0;
}
