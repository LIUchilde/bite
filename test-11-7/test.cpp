#include<iostream>
using namespace std;
#if 0
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
void TestFunc() {
	auto_ptr<int>ap1(new int);
	auto_ptr<int>ap2(ap1);
	ap1 = ap2;
}
int main() {
	TestFunc();
	return 0;
}
#endif

#if 0
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
	auto_ptr(const auto_ptr<int>& ap)
		:_ptr(ap._ptr)
		, _owner(ap._oener)
	{
		ap._owner = false;
	}
	auto_ptr<T>& operator=(const auto_ptr<int>& ap) {
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
void TestFunc() {
	auto_ptr<int>ap1(new int);
	auto_ptr<int>ap2(ap1);
	ap1 = ap2;
	if (true) {
		auto_ptr<int>ap3(ap2);
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

template<class T>
class unique_ptr {
public:
	unique_ptr(T*_prt=nullptr)
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
	//c++98
//private:
//	unique_ptr(const unique_ptr<int>& up);
//	unique_ptr<int>& operator=(const unique_ptr<int>& up);
//c++11
	unique_ptr(const unique_ptr<int>& up) = delete;
	unique_ptr<int>& operator=(const unique_ptr<int>& up) = delete;
private:
	T* _ptr;
};
void TestFunc() {
	unique_ptr<int>up1(new int);
	unique_ptr<int>up2(up1);
	up1 = up2;
}
int main() {
	TestFunc();
	return 0;
}