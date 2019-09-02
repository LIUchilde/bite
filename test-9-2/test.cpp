#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//typedef int(*FP_CALC)(int, int);
//int add(int a, int b) {
//	return a + b;
//}
//int sub(int a, int b) {
//	return a - b;
//}
//int mul(int a, int b) {
//	return a * b;
//}
//int div(int a, int b) {
//	return  a / b;
//}
////根据操作符返回相应函数的地址
//FP_CALC get_funAddr(char op) {
//	switch (op) {
//	case'+':
//		return add;
//	case'-':
//		return sub;
//	case'*':
//		return mul;
//	/*case'/':
//		return div;*/
//	default:
//		return NULL;
//	}
//	return NULL;
//}
//int calc(int a, int b, char op) {
//	FP_CALC fp = get_funAddr(op);
//	if (fp) {
//		return (*fp)(a, b);
//	}
//	else {
//		return -1;
//	}
//}
//	int main() {
//		int a = 100, b = 20;
//		cout << calc(a, b, '+')<<endl;
//		cout <<  calc(a, b, '-')<<endl;
//		cout <<  calc(a, b, '*')<<endl;
//		cout << calc(a, b, '/')<<endl;
//		return 0;
//	}
////指针函数的声明
//int* pfun(int* arr, int n);
////指针函数的定义
//int* pfun(int* arr, int n) {
//	int* p = arr;
//	return p;
//}
//int main() {
//	int arr[] = { 0,1,2,3 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int* p;
//	int i;
//	//指针函数的调用
//	p = pfun(arr, size);
//	for (i = 0;i < size;i++) {
//		cout <<  *(p + i) << endl;
//	}
//	return 0;
//}

//template<typename T>
//void Swap(T& left, T& right) {
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main() {
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a <<" "<< b << endl;
//	return 0;
//}

//template<class T>
//T Add(const T& a, const T& b) {
//	return  a + b;
//}
//int main() {
//	//隐式类型实例化：没有直接指明T的实际类型，T的类型需要进行参数推演进行确定
//	//编译器不会对参数推演的结果进行隐式类型转化
//	cout << Add(1, 2) << endl;
//	cout << Add(1.0, 2.0) << endl;
//	cout << Add('1', '2')<<endl;
//	//显式实例化：明确指定T的实际类型,参数不匹配时，可能会发生隐式类型转化
//	cout << Add<int>(1, 2.0) << endl;
//	return 0;
//}

//class Complex {
//public:
//	Complex(double real, double image)
//		:_real(real)
//		,_image(image)
//	{}
//	Complex operator+(const Complex& c)const {
//		//无名对象
//		return Complex(_real + c._real, _image + c._image);
//	}
//private:
//	double _real;
//	double _image;
//};
//int main() {
//	Complex c1(1.0, 2.0);
//	Complex c2(3.0, 4.0);
//	Add(c1, c2);
//	return 0;
//}

//int Add(int a, int b) {
//	return a + b;
//}
//template<class T1,class T2>
//T1 Add(const T1& a, const T2& b) {
//	return a + b;
//}
//int main() {
//	Add(1, 2);
//	Add<>(1, 2);
//	Add(1, 2.0);
//	return 0;
//}


template<class T>
class SeqList{
public:
	SeqList(size_t capacity = 10)
		:_array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}
	SeqList(size_t n, const T& data = T())
		:_array(new T[n])
		, _capacity(n)
		, _size(n)
	{
		for (size_t i = 0;i < _size;i++) {
			_array[i] = data;
		}
	}
	~SeqList() {
		if (_array) {
			delete[]_array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	void pushBack(const T& data);
	void PopBack();
	size_t Size()const {
		return _size;
	}
	size_t capacity()const {
		return _capacity;
	}
	bool Empty()const {
		return 0 == _size;
	}
	T& operator[](size_t index) {
		assert(index < _size);
		return _array[index];
	}
	const T& operator[](size_t index)const {
		assert(index < _size);
		return _array[index];
	}
	void print() {
		for (size_t i = 0;i < _size;i++) {
			cout << _array[i] << " ";
		}
		cout << endl;
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
template<class T>
void SeqList<T>::pushBack(const T& data) {
	_array[_size++] = data;
}
template<class T>
void SeqList<T>::PopBack() {
	if (0 == _size) {
		return;
	}
	--_size;
}
int main() {
	SeqList<int> s1;
	s1.pushBack(1);
	s1.pushBack(1);
	s1.pushBack(2);
	s1.pushBack(3);
	s1.pushBack(4);
	s1.print();
	s1[0] = 0;
	s1.print();
	cout << s1.Size() << endl;
	cout << s1.capacity() << endl;
	cout << s1[3] << endl;
	const SeqList<int> s2(10,5);
	cout << s2[5] << endl;
	return 0;
}
