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
		//�ӻ���̳������ĳ�Ա������ֵ
		_pub = pub;
		_pro = pro;
		//_pri = pri;//�����private��Ա����ֱ�ӱ�ʹ�ã������Ѿ����̳�������
		//�����¼ҵĳ�Ա������ֵ
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
		//�ӻ���̳������ĳ�Ա������ֵ
		//����Ǳ����ļ̳з�ʽ�������б�public�����޶������εĳ�Ա�����������е�Ȩ���Ѿ���Ϊprotected
		_pub = pub;
		//����Ǳ����ļ̳з�ʽ�������б�protected�����޶������εĳ�Ա�����������е�Ȩ�޲���
		_pro = pro;
		//_pri = pri;//�����private��Ա����ֱ�ӱ�ʹ�ã������Ѿ����̳�������
		//�����¼ҵĳ�Ա������ֵ
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
		//�ӻ���̳������ĳ�Ա������ֵ
		//�����˽�еļ̳з�ʽ�������б�public�����޶������εĳ�Ա�����������е�Ȩ���Ѿ���Ϊprivate
		_pub = pub;
		//�����˽�еļ̳з�ʽ�������б�protected�����޶������εĳ�Ա�����������е�Ȩ���Ѿ���Ϊprivate
		_pro = pro;
		//_pri = pri;//�����private��Ա����ֱ�ӱ�ʹ�ã������Ѿ����̳�������
		//�����¼ҵĳ�Ա������ֵ
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

//ͬ�����أ��ڻ���������о�����ͬ���Ƶĳ�Ա����Ա��������Ա������
//          ���ʹ������Ķ�����ʼ̳���ϵ��ͬ���ĳ�Ա�����ʵĶ�������ĳ�Ա
//          ������ͬ���ĳ�Ա��Զ���ʲ������൱������ͬ����Ա��������ͬ����Ա���أ�


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
	//�����๹�캯��һ��Ҫ�����ʼ���б��λ�õ��û���Ĺ��캯��
	   //�������Զ����û���Ĭ�ϵĹ��캯��
	   //��Ҫ�û���ʽ�������๹�캯���б��н��е���
	//����������ȱʡ�Ĺ��캯�����޲λ�ȫȱʡ�Ĺ��캯����������Ĺ��캯������ʵ��Ҳ���Բ�ʵ��
	//���������ʾ����ķ�ȱʡ�Ĺ��캯��������������ڳ�ʼ���б�λ����ʽ���û���Ĺ��캯��
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
	//�����Ǹ���Ķ��󣬵����Ǹ���Ĺ���
	//�����ĸ���Ķ��󣬵����ĸ��������
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
