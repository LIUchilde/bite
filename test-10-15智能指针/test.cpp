#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
//RAII+具有指针的行为（解引用，->)
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
	//1:通过RAII的方式管理指针
	//2：具有像指针的行为：解引用，->
	//3:解决浅拷贝问题(深拷贝（不行）)原因：资源是外部用户提供的，类只负责管理资源，没有申请资源的权利
	//c++98 auto_ptr:资源转移
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
	//ap1和ap2为野指针，会造成程序崩溃
}
int main() {
	TestFunc();
	return 0;
}
#endif

#if 0
//unique_ptr:一份资源只能让一个对象管理，不允许共享
//不能被拷贝
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
		//sp1：未管理资源--直接与sp2共享
		//sp1：单独管理资源--在与sp2共享前，必须先释放自己的资源
		//sp1：与其他shared_ptr的对象已经共享资源--sp1将其计数减1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
			if (_ptr!=sp._ptr) {
				Release();
				//与sp共享
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
	sp4 = sp1;//sp4未管理资源
	sp3 = sp1;//sp3单独管理一份资源--释放旧资源，与sp1共享
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
				//与sp共享
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
				//等价于
				DF()(_ptr);//DF是一个类型  DF()：创建一个无名对象
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

//shared_ptr:循环引用问题
//weak_ptr:不能单独管理资源，必须配合shared_ptr一起使用
//         因为weak_ptr作用：就是为了解决shared_ptr存在的循环引用问题而生的
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
	//编译报错：weak_ptr不能单独管理资源
	//weak_ptr<int>wp(new int);
	TestFunc();
	return 0;
}