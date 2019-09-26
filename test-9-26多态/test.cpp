#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0
class Base {
public:
	virtual void TestFunc() {
		cout << "Base::Base()" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::TestFunc2" << endl;
	}
private:
	int _b;
};
int main() {
	Base b;
	cout << sizeof(b) << endl;
	return 0;
}
#endif

#if 0
class Base {
public:
	virtual void TestFunc1() {
		cout << "Base::TestFunc1" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::TestFunc2" << endl;
	}
	void TestFunc3() {
		cout << "Base::TestFunc3" << endl;
	}
private:
	int _b;
};
class Derived : public Base {
public:
	virtual void TestFunc1() {
		cout << "Derived::TestFunc1" << endl;
	}
private:
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
	cout << sizeof(b) << endl;
	cout << sizeof(d) << endl;
	Test(b);
	Test(d);
	return 0;
}
#endif

class Base {
public:
	virtual void TestFunc3() {
		cout << "Base::TestFunc3" << endl;
	}
	virtual void TestFunc1() {
		cout << "Base::TestFunc1" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::TestFunc2" << endl;
	}
private:
	int _b;
};
class Derived : public Base {
public:
	virtual void TestFunc5() {
		cout << "Derived::TestFunc" << endl;
	}
	virtual void TestFunc1() {
		cout << "Derived::TestFunc1" << endl;
	}
	virtual void TestFunc3() {
		cout << "Derived::TestFunc3" << endl;
	}
	virtual void TestFunc4() {
		cout << "Derived::TestFunc4" << endl;
	}
};
int main() {
	Base b;
	Derived d;
	return 0;
}
