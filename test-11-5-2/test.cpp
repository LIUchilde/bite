#include<iostream>
using namespace std;
#if 0
class person {
public:
	void print() {
		cout << _name << endl;
		cout << _age << endl;
	}
private:
	string _name = "����";
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
	cout << sizeof(person) << endl;
	cout << sizeof(s) << endl;
	cout << sizeof(t) << endl;
	s.print();
	t.print();
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
	D(int b, int d)
		:B(b)
		, _d(d)
	{}
	D(const D& d)
		:B(d._b)
		, _d(d._d)
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
	D d(10, 20);
	return 0;
}
#endif

#if 0
class A final {
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
#endif

#if 0
class B {
	friend void TestFunc();
public:
protected:
	int _b;
};
class D :public B {
protected:
	int _d;
};
void TestFunc() {
	//�ú���Ϊ�������Ԫ
	//�����ڸú����з��ʻ��ౣ����˽�еĳ�Ա
	B b;
	b._b = 10;
	//���ܷ���������˽�л򱣻��ĳ�Ա
	D d;
	d._d = 20;
	//���ۣ���Ԫ��ϵ���ܱ��̳�
	//�̳У�����һ���̳е��ǻ���ĳ�Ա����Ԫ�����ڻ���ĳ�Ա
}
int main() {
	return 0;
}
#endif

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
		_count = 20;
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
public:
	int _b;
};
class C1 :public B {
public:
	int _c1;
};
class C2 :public B {
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
	//���Խ�����������⣬�����������޷����
	d.C1::_b = 10;
	d._c1 = 20;
	d.C2::_b = 30;
	d._c2 = 40;
	d._d = 50;
	return 0;
}
#endif 

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
	cout << sizeof(d) << endl;
	d._b = 10;
	d._c1 = 20;
	d._b = 30;
	d._c2 = 40;
	d._d = 50;
	return 0;
}