#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
class string {
public:
	string(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	string(const string& s)
		:_str(new char[strlen(s._str)+1])
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
		return *this;
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
	std::string s1;
	std::string s2("hello");
	std::string s3(s2);
	std::string s4("world");
	s4 = s3;
	return 0;
}
#endif

#if 0
class string {
public:
	string(const char* str = " ") {
		if (str == nullptr) {
			str = " ";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_pCount = new int(1);
	}
	string(const string& s)
		:_str(s._str)
		,_pCount(s._pCount)
	{
		++(*_pCount);
	}
	string& operator=(const string& s) {
		if (this != &s) {
			if (0 == -- * _pCount) {
				delete[]_str;
				delete[]_pCount;
			}
			_str = s._str;
			_pCount = s._pCount;
			++* _pCount;
		}
		return *this;
	}
	~string() {
		if (_str&&0==--*_pCount) {
			delete[]_str;
			_str = nullptr;
			delete _pCount;
			_pCount = nullptr;
		}
	}
private:
	char* _str;
	 int* _pCount;
};
int main() {
	std::string s1;
	std::string s2("hello");
	std::string s3(s2);
	return 0;
}
#endif

#include<assert.h>
class string {
public:
	typedef char* iterator;
public:
	string(const char* str = " ") {
		if (str == nullptr) {
			str = " ";
		}
		_size = strlen(str);
		_str = new char[_size+ 1];
		strcpy(_str, str);
		_capacity = _size;
	}
	string(size_t n, char ch)
		:_str(new char[n + 1])
		, _size(n)
		, _capacity(n)
	{
		memset(_str, ch, _size);
		_str[_size] = '\0';
	}
	string(const string& s)
		:_size(s._size)
		, _capacity(s._size)
	{
		_str = new char[_size + 1];
		strcpy(_str, s._str);
	}
	string& operator=(const string& s) {
		if (this != &s) {
			char* str = new char[s._size + 1];
			strcpy(str, s._str);
			delete[]_str;
			_str = str;
			_size = s._size;
			_capacity = _size;
		}
		return *this;
	}
	~string() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}
	char& operator[](size_t index) {
		assert(index < _size);
		return _str[index];
	}
	const char& operator[](size_t index)const {
		assert(index < _size);
		return _str[index];
	}
	size_t size()const {
		return _size;
	}
	size_t capacity()const {
		return _capacity;
	}
	void resize(size_t newsize, char ch=char()) {
		size_t oldsize = _size;
	if(newsize>oldsize) {
			if (newsize > _capacity) {
				reserve(_capacity);
			}
			memset(_str + _size, ch, newsize - oldsize);
		}
		_size = newsize;
		_str[_size] = '\0';
	}
	void reserve(size_t newcapacity) {
		if (newcapacity > _capacity) {
			char* str = new char[newcapacity + 1];
			strcpy(str, _str);
			delete[]_str;
			_str = str;
			_capacity = newcapacity;
		}
	}
	string& operator+=(char ch) {
		if (_size = _capacity) {
			reserve(2 * _capacity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
	}
	string& operator+=(char* str) {
		size_t len = strlen(str);
		size_t newsize = size() + len;
		if (capacity() < newsize) {
			reserve(newsize);
		}
		strcat(_str, str);
		_size = newsize;
		return *this;
	}
	string& operator+=(const string& s) {
		*this += s._str;
		return *this;
	}
	void swap(string& s) {
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	const char* c_str()const {
		return _str;
	}
	size_t find(char ch) {
		for (size_t i = 0;i < size();i++) {
			if (_str[i] == ch) {
				return i;
			}
		}
		return -1;
	}
	iterator begin() {
		return _str;
	}
	iterator end() {
		return _str + _size;
	}
private:
	char* _str;
	size_t _capacity;
	size_t _size;
};
int main() {
	std::string s1;
	std::string s2("hello");
	std::string s3(10, '!');
	std::string s4(s2);
	s3 = s4;
	s4[0] = 'a';
	s4.swap(s2);
	return 0;
}