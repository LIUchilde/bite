#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
double Division(int a, int b) {
	if (b == 0) {
		throw"Division by zero condition!";
	}
	else {
		return ((double)a) / ((double)b);
	}
}
	void Func() {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	int main() {
		try {
			Func();
		}
		catch (const char* errmsg) {
			cout << errmsg << endl;
		}
		catch (...) {
			cout << "nukown exception" << endl;
		}
		return 0;
	}
#endif

#if 0
double Division(int a, int b) {
	if (b == 0) {
		throw"Division by zero condition!";
		}
	return (double)a / (double)b;
}
void Func() {
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...) {
		cout << "delete[]" << array << endl;
		delete[]array;
		throw;
	}
}
int main() {
	try {
		Func();
	}
	catch (const char* errsg) {
		cout << errsg << endl;
	}
	return 0;
}
#endif

#if 0
class Exception {
protected:
	string _errmsg;
	int _id;
};
class sqlException:public Exception
{};
class CacheException:public Exception
{};
class HttpServerException:public Exception
{};
int main() {
	try {
		//serve.start();
		//�׳����������������
	}
	catch(const Exception&e)//���ﲶ�������Ϳ���
	{ }
	catch (...)
	{
		cout << "nukown Exception" << endl;
	}
	return 0;
}
#endif

