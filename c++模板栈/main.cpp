#define  _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include<stdlib.h>
int main() {
	stack<int>s;
	s.push(&s,1);
	s.push(&s,2);
	s.push(&s,3);
	s.pop(&s);
	s.size(&s);
	s.Top(&s);
	s.Clear(&s);
	while (!s.empty(&s)) {
		cout << s.pop(&s) << endl;
	}
	system("pause");
	return 0;
}