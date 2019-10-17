#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
//定义一个模板类型的静态数组
template<class  T,size_t N=10>
class array {
public:
	T& operator[](size_t index) {
		return _array[index];
	}
	const T& operator[](size_t index)const {
		return _array[index];
	}
	size_t size()const {
		return _size;
	}
	bool empty()const {
		return 0 == _size;
	}
private:
	T _array[N];
	size_t _size;
};
int main() {
	return 0;
}
#endif

#if 0
template<class T>
bool IsEqual(T& left, T& right) {
	return left == right;
}
void Test(){
	char p1[] = "hello";
	char p2[] = "world";
	if (IsEqual(p1, p2)) {
		cout << p1 << endl;
	}
	else {
		cout << p2 << endl;
	}
}
int main() {
	Test();
	return 0;
}
#endif
#if 0
 template<class T>
 T max(T left, T right) {
	 return left > right ? left : right;
 }
 int main() {
	const char* p1 = "world";
	const char* p2 = "hello";
	cout << max(p1, p2) << endl;//判断的是指针的大小
	return 0;
 }
#endif

#if 0
 char* max(  char*  left,  char* right) {
	 if (strcmp(left,right) > 0) {
		 return left;
	 }
	 else {
		 return right;
	 }
 }
 int main() {
	 char p1[] = "world";
	  char p2[] = "hello";
	 cout << max(p1, p2) << endl;
	 return 0;
 }
#endif

#if 0
 template<class T>
 T max(T left, T right) {
	 return left > right ? left : right;
 }
 template<>
 char* max<char*>( char* left,  char* right) {
	 return left > right ? left : right;
 }
 int main() {
	 const char* p1 = "world";
	 const char* p2 = "hello";
	 cout << max(p1, p2) << endl;
	 //工程中是否存在类型完全匹配的普通函数  存在 匹配
	 //不存在  模板特化
	 //模板生成
	 return 0;
 }
#endif

 //实现一个通用的拷贝函数
 template<class T>
 void copy(T* dest, T* src, size_t N) {
	 //memcpy(dest, src, sizeof(T) * N);
	 for (size_t i = 0;i < N;++i) {
		 dest[i] = src[i];
	 }
 }
 class string {
 public:
	 string(const char* str = " ") {
		 if (nullptr == str) {
			 str = " ";
		 }
		 _str = new char[strlen(str) + 1];
		 strcpy(_str, str);
	 }
	 string(const string& s) 
		 :_str(new char[strlen(s._str) + 1])
	 {
		 strcpy(_str, s._str);
	 }
	 string& operator=(const string& s) {
		 if (this != &s) {
			 char* str = new char[strlen(s._str) + 1];
			 strcpy(str, s._str);
			 delete[]_str;
			 _str = str;
		 }
	 }
	 ~string() {
		 if (_str) {
			 delete[]_str;
			 _str = nullptr;
		 }
	 }	 
 private:
	 char* _str;
 };
 int main() {
	 int array1[] = { 1,2,3,4,5,6,7,8,9,0 };
	 int array2[sizeof(array1) / sizeof(array1[0])];
	 copy(array2, array1, sizeof(array1) / sizeof(array1[0]));
	 std::string s1[] = { "111","222","333","444" };
	 std::string s2[4];
	 copy(s2, s1, sizeof(s1));
	 return 0;
 }
