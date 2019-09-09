#define  _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include<assert.h>
char& String::operator[](size_t index) {
	assert(index < _size);
		return _str[index];
}
const char& String::operator[](size_t index)const {
	assert(index < _size);
	return _str[index];
}
size_t String::size()const {
	return _size;
}
size_t String::capacity()const {
	return _capacity;
}
bool String::empty()const {
	return 0==_size;
}
void String::resize(size_t newsize, char ch) {
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
void String::reserve(size_t newcapacity) {
	if (newcapacity > _capacity) {
		char* str = new char[newcapacity + 1];
		strcpy(str,_str);
		delete[]_str;
		_str = str;
		_capacity = newcapacity;
	}
}
String& String::operator+=(char ch) {
	if (_size == _capacity) {
		reserve(2 * _capacity);
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
	}
}
String& String::operator+=(char* str) {
	size_t len = strlen(str);
	size_t newsize = size() + len;
	if (capacity() < newsize) {
		reserve(newsize);
	}
	strcat(_str, str);
	_size = newsize;
	return *this;
}
String& String::operator+=(const String& s) {
	*this += s._str;
	return *this;
}