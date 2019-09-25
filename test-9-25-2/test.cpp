#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//#if 0
void replaceSpace(char* str, int length) {
	if (str == nullptr || length <= 0) {
		return;
	}
	int oldlength = 0;
	int count = 0;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			count++;
		}
		oldlength++;
		i++;
	}
	int newlength = oldlength + 2 * count;
	if (newlength > length) {
		return;
	}
	int oldindex = oldlength;
	int newindex = newlength;
	while (oldindex >= 0 && newindex >= 0) {
		if (str[oldindex] == ' ') {
			str[newindex--] = '0';
			str[newindex--] = '2';
			str[newindex--] = '%';
		}
		else {
			str[newindex--] = str[oldindex];
		}
		oldindex--;
	}
	//for (int i = 0;i < newlength;i++) {
	//	cout << str[i];
	//}
	//cout << endl;
}
int main() {
	char str[] = "We are family";
	replaceSpace(str, 50);
	return 0;
}
//#endif 
