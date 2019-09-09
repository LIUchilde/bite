#pragma once
#include<cstring>
class String {
public:
	String( const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_size = strlen(str);
		_str = new char[_size+ 1];
		strcpy(_str, str);
		_capacity = _size;
	} 
	String(const String& s)
		:_size(s._size)
		,_capacity(s._size)
	{
		_str = new char[_size + 1];
		strcpy(_str, s._str);
	}
	String(size_t n, char ch)
		:_str(new char[n + 1])
		, _size(n)
		, _capacity(n)
	{
		memset(_str, ch, _size);
		_str[_size] = '\0';
	}
	String& operator=(const String& s) {
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
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}
	char& operator[](size_t index);
	const char& operator[](size_t index)const;
	size_t size()const;
	size_t capacity()const;
	bool empty()const;
	void resize(size_t newsize, char ch);
	void reserve(size_t newcapacity);
	String& operator+=(char ch);
	String& operator+=(char* str);
	String& operator+=(const String& s);
private:
	char* _str;
	size_t _capacity;
	size_t _size;
};
