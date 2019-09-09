#pragma once
#include<cstring>
#include<ostream>
class string {
public:
	typedef char* iterator;
public:
	string(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;
	}
	string(const string& s);
	string(size_t n, char ch);
	string& operator=(const string& s);
   ~string();
	char& operator[](size_t index);
	const char& operator[](size_t index)const;
	size_t size()const;
	size_t capacity()const;
	bool Empty()const;
	void resize(size_t newsize, char ch );
	void reserve(size_t newcapacity);
	string& operator+=(char ch);
	string& operator+=(char* str);
	string& operator+=(string& s);
	void swap(string& s);
	const char* c_str()const;
	size_t find(char ch);
	size_t rfind(char ch);
	string substr(size_t pos = 0, size_t n = npos) {
		string strRet;
		if (n == npos) {
			n = size() - pos;
		}
		strRet.reserve(n);
		strncpy(strRet._str, _str + pos, n);
		strRet._size = n;
		strRet[n] = '\0';
		return strRet;
	}
	friend std::ostream& operator<<(std::ostream& _cout, const string& s) {
		_cout << s.c_str();
		return _cout;
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
	static size_t npos;
};
size_t string:: npos=0;
