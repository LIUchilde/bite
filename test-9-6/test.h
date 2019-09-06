#pragma once
#include<cstring>
#if 0
class string {
public:
	string(const char* str = "") {
		//if (str == nullptr) {
		//	_str = new char[1];
		//	*_str = '\0';
		//}
		//else {
		//	_str = new char[strlen(str) + 1];
		//	strcpy(_str, str);
		//}
		if (nullptr == str) {
			str = "";
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
		return *this;
	}
	~string()
	{
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
#endif

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
		:_str(nullptr)
	{
		string strTemp(s._str);
		swap(_str, strTemp._str);
	}
	string& operator=(string s) {
		swap(_str, s._str);
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
#endif

//Ð´Ê±¿½±´
class string {
public:
	string(const char* str = "") {
		if (nullptr == str) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_Pcount = new int(1);
	}
	string(string&s)
		:_str(s._str)
		,_Pcount(s._Pcount)
	{
		++(*_Pcount);
	}
	string& operator=(const string& s) {
		if (this != &s) {
			if (0 == -- * _Pcount) {
				delete[]_str;
				delete[]_Pcount;
			}
			_str = s._str;
			_Pcount = s._Pcount;
			++* _Pcount;
		}
		return *this;
	}
	~string() {
		if (_str && 0 == --(*_Pcount)) {
			delete[]_str;
			_str = nullptr;
			delete _Pcount;
			_Pcount = nullptr;
		}
	}
		char& operator[](size_t index) {

			return _str[index];
		}
		const char& operator[](size_t index)const {
			return _str[index];
		}
private:
	char* _str;
	 int* _Pcount;
};

