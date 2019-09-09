#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include<cstring>
#include<assert.h>
string::string(const string& s)
	:_size(s._size)
	, _capacity(s._capacity)
{
	_str = new char[_size + 1];
	strcpy(_str, s._str);
}
string::string(size_t n, char ch)
	:_str(new char[n + 1])
	, _size(n)
	, _capacity(n)
{
	memset(_str, ch, _size);
	_str[_size] = '\0';
}
string& string:: operator=(const string& s)
{
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
string::~string() {
	if (_str) {
		delete[]_str;
		_str = nullptr;
	}
}
char& string::operator[](size_t index) {
	assert(index < _size);
	return _str[index];
}
const char& string::operator[](size_t index)const {
	assert(index < _size);
	return _str[index];
}
size_t string::size()const {
	return _size;
}
size_t string::capacity()const {
	return _capacity;
}
bool string::Empty()const {
	return 0 == _size;
}
void string::resize(size_t newsize, char ch) {
	size_t oldsize = _size;
	if (newsize > oldsize) {
		if (newsize > _capacity) {
			reserve(_capacity);
		}
		memset(_str + _size, ch, newsize - oldsize);
	}
	_size = newsize;
	_str[_size] = '\0';
}
void string::reserve(size_t newcapacity) {
	if (newcapacity > _capacity) {
		char* str = new char[newcapacity];
		strcpy(str, _str);
		delete[]_str;
		_str = str;
		_capacity = newcapacity;
	}
}
string& string::operator+=(char ch) {
	if (_size == _capacity)
		reserve(2 * _capacity);
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
}
string& string::operator+=(char* str) {
	size_t len = strlen(str);
	size_t newsize = len +size();
	if (capacity()<len+size()) {
		reserve(newsize);
	}
	strcat(_str, str);
	_size = newsize;
	return *this;
}
string& string::operator+=(string& s) {
	*this += s._str;
	return *this;
}
void string::swap(string& s) {
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}
const char* string::c_str()const {
	return _str;
}
size_t string::find(char ch) {
	for (size_t i = 0;i < _size;i++) {
		if (_str[i] == ch)
			return i;
	}
	return npos;
}
size_t string::rfind(char ch) {
	for (size_t i = _size-1;i >=0;i--) {
		if (_str[i] == ch)
			return i;
	}
	return npos;
}


			

