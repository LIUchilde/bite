#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
//RAII+����ָ�����Ϊ�������ã�->)
template<class T>
class smartptr {
public:
	smartptr(T*ptr=nullptr)
		:_ptr(ptr)
	{}
	~smartptr() {
		if (_ptr) {
			delete _ptr;
		}
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
private:
	T* _ptr;
};
struct A {
	int a;
	int b;
	int c;
};
void TestFunc() {
	smartptr<int>sp1(new int);
	*sp1 = 1;
	smartptr<A>sp2(new A);
	sp2->a = 2;
	sp2->b = 3;
	sp2->c = 4;
}
int main() {
	TestFunc();
	return 0;
}
#endif

#if 0
namespace bite {
	//1:ͨ��RAII�ķ�ʽ����ָ��
	//2��������ָ�����Ϊ�������ã�->
	//3:���ǳ��������(��������У�)ԭ����Դ���ⲿ�û��ṩ�ģ���ֻ���������Դ��û��������Դ��Ȩ��
	//c++98 auto_ptr:��Դת��
	template<class T>
	class auto_ptr {
	public:
		auto_ptr(T*ptr=nullptr)
			:_ptr(ptr)
		{}
		auto_ptr(auto_ptr<T>& ap) {
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		auto_ptr<T>& operator=(auto_ptr<T>& ap) {
			if (this != &ap) {
				if (_ptr)
					delete _ptr;
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
	private:
		T* _ptr;
	};
}
void TestFunc() {
	bite::auto_ptr<int>ap1(new int);
	bite::auto_ptr<int>ap2(ap1);
	ap1 = ap2;
}
int main() {
	TestFunc();
	return 0;
}
#endif

#if 0
namespace bite {
	template<class T>
	class auto_ptr {
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _owner(false)
		{
			if (_ptr)
				_owner = true;
		}
		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;
		}
		auto_ptr<T>&operator= (const auto_ptr<T>& ap) {
			if (this != &ap) {
				Release();
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}
		~auto_ptr() {
			Release();
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
	private:
		void Release() {
			if (_ptr && _owner) {
				delete _ptr;
			}
		}
	private:
		T* _ptr;
		mutable bool _owner;
	};
}
void TestFunc() {
	bite::auto_ptr<int>ap1(new int);
	bite::auto_ptr<int>ap2(ap1);
	ap1 = ap2;
	if (true) {
		bite::auto_ptr<int>ap3(ap2);
	}
	*ap1 = 10;
	*ap2 = 20;
	//ap1��ap2ΪҰָ�룬����ɳ������
}
int main() {
	TestFunc();
	return 0;
}
#endif

#if 0
//unique_ptr:һ����Դֻ����һ�����������������
//���ܱ�����
namespace bite {
	template<class T>
	class unique_ptr {
	public:
		unique_ptr(T*ptr=nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr() {
			if (_ptr)
				delete _ptr;
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
	//	//c++98
	//private:
	//	unique_ptr(const unique_ptr<int>& up);
	//	unique_ptr<T>& operator=(const unique_ptr<int>& up);
	//c++11
		unique_ptr(const unique_ptr<int>& up) = delete;
		unique_ptr<int>& operator=(const unique_ptr<int>& up) = delete;
	private:
		T* _ptr;
	};
}
void TestFunc() {
	bite::unique_ptr<int>up1(new int);
	bite::unique_ptr<int>up2(up1);
	up1 = up2;
}
int main() {
	TestFunc();
	return 0;
}
#endif

#if 0
namespace bite {
	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T*ptr=nullptr)
			:_ptr(ptr)
			,_pCount(nullptr)
		{
			if (_ptr) {
				_pCount = new int(1);
			}
		}
		~shared_ptr() {
			Release();
		}
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr) {
				++(*_pCount);
			}
		}
		//sp1��δ������Դ--ֱ����sp2����
		//sp1������������Դ--����sp2����ǰ���������ͷ��Լ�����Դ
		//sp1��������shared_ptr�Ķ����Ѿ�������Դ--sp1���������1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
			if (_ptr!=sp._ptr) {
				Release();
				//��sp����
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr) {
					++(*_pCount);
				}
			}
			return *this;
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
		int usecount() {
			return *_pCount;
		}
	private:
		void Release() {
			if (_ptr && 0 == (-- * _pCount)) {
				delete _ptr;
				delete _pCount;
			}
		}
	private:
		T* _ptr;
		int* _pCount;
	};
}
void TestFunc() {
	bite::shared_ptr<int>sp1(new int);
	bite::shared_ptr<int>sp2(sp1);
	bite::shared_ptr<int>sp3(new int);
	bite::shared_ptr<int>sp4;
	sp4 = sp1;//sp4δ������Դ
	sp3 = sp1;//sp3��������һ����Դ--�ͷž���Դ����sp1����
	sp1 = sp2;
}
#endif 

#if 0
template<class T>
class DFDel {
public:
	void operator()(T*& p) {
		if (p) {
			delete p;
			p = nullptr;
		}
	}
};
template<class T>
class Free {
public:
	void operator()(T*& p) {
		if (p) {
			free(p);
			p = nullptr;
		}
	}
};
class FClose {
public:
	void operator()(FILE* p) {
		if (p) {
			fclose(p);
			p = nullptr;
		}
	}
};
namespace bite {
	template<class T,class DF=DFDel<T>>
	class shared_ptr {
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr) {
				_pCount = new int(1);
			}
		}
		~shared_ptr() {
			Release();
		}
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr) {
				++(*_pCount);
			}
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
			if (_ptr != sp._ptr) {
				Release();
				//��sp����
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr) {
					++(*_pCount);
				}
			}
			return *this;
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
		int usecount() {
			return *_pCount;
		}
	private:
		void Release() {
			if (_ptr && 0 == (-- * _pCount)) {
				//DF df;
				//df(_ptr);
				//�ȼ���
				DF()(_ptr);//DF��һ������  DF()������һ����������
				delete _pCount;
			}
		}
	private:
		T* _ptr;
		int* _pCount;
	};
}
void TestFunc() {
	bite::shared_ptr<int,Free<int>>sp1((int*)malloc(sizeof(int)));
	bite::shared_ptr<FILE,FClose>sp2(fopen("666.txt", "rb"));
	bite::shared_ptr<int>sp3(new int);
}
int main() {
	TestFunc();
	return 0;
}
#endif

//shared_ptr:ѭ����������
//weak_ptr:���ܵ���������Դ���������shared_ptrһ��ʹ��
//         ��Ϊweak_ptr���ã�����Ϊ�˽��shared_ptr���ڵ�ѭ���������������
#include<memory>
struct ListNode {
	ListNode(int data=int())
		/*:_pre(nullptr)
		,_next(nullptr)
		,_data(data)*/
		:_data(data)
	{
		cout << "ListNode():" << this << endl;
	}
	~ListNode() {
		cout << "~ListNode():" << this << endl;
	}
	//shared_ptr<ListNode>_pre;
	//shared_ptr<ListNode>_next;
    weak_ptr<ListNode>_pre;
	weak_ptr<ListNode>_next;
	int _data;
};
void TestFunc() {
	shared_ptr<ListNode>sp1(new ListNode(10));
	shared_ptr<ListNode>sp2(new ListNode(20));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	sp1->_next = sp2;
	sp2->_next = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}
int main() {
	//���뱨��weak_ptr���ܵ���������Դ
	//weak_ptr<int>wp(new int);
	TestFunc();
	return 0;
}