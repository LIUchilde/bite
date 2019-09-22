#define  _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int main() {
//	int a, b;
//	while (1) {
//		cin >> a >>b;
//		if (a <= 0 || b >= 1000000) {
//			break;
//		}
//		else {
//			cout << a + b << endl;
//		}
//	}
//	return 0;
//}

#if 0
#include<iostream>
using namespace std;
#include<vector>

void reOrderArray(vector<int>& array) {
	for (unsigned int i = 0;i < array.size(); ++ i) {
		for (unsigned int j = array.size() - 1;j > i;j--) {
			if ((array[j-1]) % 2 == 0 && array[j] % 2 == 1) {
				swap(array[j - 1], array[j]);
			}
		}
	}
}
int main() {
	vector<int> array;
	array = { 1,2,3,4,5 };
	reOrderArray(array);
	for (int i = 0;i < 5;i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>
int MoreThanHalfNum_Solution(vector<int> numbers) {
	int size = numbers.size();
	int count=0;
	for (int i = 0;i < size;i++) {
		for (int j = i;j < size;j++) {
			if (numbers[i] == numbers[j])
				count++;
		}
				if (count > size / 2) {
					cout << numbers[i] << endl;;
					return numbers[i];
				}
				else{
					count = 0;
			}
		}
	cout << 0;
	return 0;
}
int main() {
	vector<int>array;
	array = { 1,3,3,5,3,3,7 };
	MoreThanHalfNum_Solution(array);
	return 0;
}
#endif


#include<iostream>
using namespace std;
#include<string>
string remove(string s) {
	int len = s.size();
	if (len < 2) {
		return s;
	}
	string str = " ";
	for (int i = 0;i < len;i++) {
		if (s[i] != ' ') {
			str += s[i];
		}
		for (int j = i + 1;j < len;j++) {
			if (s[j] == s[i]) {
				s[j] = ' ';
			}
		}
	}
	return str;
}
int main() {
	string s1 = "asdas";
	string s2 = "asd";
	string s3 = "aaaa";
	cout << remove(s1) << endl;
	cout << remove(s2) << endl;
	cout << remove(s3) << endl;
	return 0;
}

