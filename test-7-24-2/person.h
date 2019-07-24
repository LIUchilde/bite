#pragma once
class person {
public:
	void setpersonInfo(const char* name, const char* gender, int age);
	void printpersonInfo();
public:
	char _name[20];
	char _gender[5];
	int _age;
};
