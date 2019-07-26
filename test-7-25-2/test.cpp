#define  _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Maxsize 100
typedef struct stack {
	int* top;//ջ��ָ�룬һֱ��ջ��Ԫ����һ��λ��
	int* base;//ջ��ָ�룬һֱ����
	int stacksize;//ջ���õ��������
}stack;
int length = 0;
//��ʼ������
int Initstack(stack &s) {
	s.base = new int[Maxsize];//��̬�����������
	if (!s.base)
	{
		cout << "����ʧ��" << endl;
		return 0;
	}
	s.top = s.base;
	s.stacksize = Maxsize;
	return 1;
}
//��ջ
int stackpush(stack& s, int val) {
	if (s.top - s.base == s.stacksize) {//ջ��
		return 0;
	}
	else {
		(*s.top++) = val;
		length++;
	}
	return 1;
}
//��ջ����val����
int stackpop(stack& s, int *val) {
	if (s.base == s.top) {//ջ��
		return 0;
	}
	else {
		*val = *--s.top;//�ȼ�����ָ��ջ��Ԫ�أ��ٸ���val
		length--;
	}
	return 1;
}
//ȡջ��
bool GetTop(stack& s, int* val) {
	if (s.base == s.top) {//ջ��
		return false;
	}
	else{
		*val = *(s.top-1);
	}
	return true;
}
//�ж�ջ��Ԫ�ظ���
int size(stack& s) {
	return length;
}
//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(stack& s) {
	if (s.base == s.top) {//ջ��
		return true;
	}
	else {
		return false;
	}
}
//����ջ
int Destroystack(stack& s) {
	free(s.base);
	s.base = NULL;
	s.top = NULL;
	s.stacksize = NULL;
	return NULL;
}
void menu() {
	cout << "******1:��ջ               2��:��ջ******" << endl;
	cout << "****3**3:ȡջ��             4���ж�ջ��Ԫ�ظ���" << endl;
	cout << "******5:�ж�ջ�Ƿ�Ϊ��     6������ջ" << endl;
	cout << "          **********7:�˳�**********" << endl;
}
void pushtostack(stack& s) {
	int n;
	int val;
	int flage;
	printf("��������ջԪ�ظ�����\n");
	int m=scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		printf("�������%d��ֵ", i + 1);
		int m=scanf("%d", &val);
		flage = stackpush(s,val);
		if (flage) {
			printf("%d����ջ\n", val);
		}
		else {
			printf("ջ����������\n");
			break;
		}
	}
}
void popFromstack(stack& s) {
	int n;
	int va;
	int flage;
	printf("�������ջԪ�ظ���:\n");
	int m=scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		flage = stackpop(s, &va);
		if (flage) {
			printf("%d�Գ�ջ\n", va);
		}
		else {
			printf("ջ�Կգ�����\n");
		}
	}
}
void GetTopofstack(stack& s) {
	bool flage;
	int va = 0;
	flage = GetTop(s, &va);
	if (flage) {
		printf("ջ��Ԫ��Ϊ%d\n", va);
	}
	else {
		printf("ջ�Կգ�����\n");
	}
}
void sizeofstack(stack& s) {
	printf("ջ��Ԫ�ظ���Ϊ��%d\n", length);
}
void isEmptystack(stack& s) {
	if (s.base==s.top) {
		printf("ջΪ��\n");
	}
	else {
		printf("ջ��Ϊ��\n");
	}
}
int main() {
	stack s;
	int choice;
	Initstack(s);
	while (1) {
		menu();
		printf("������˵���ţ�\n");
		int m=scanf("%d", &choice);
		if (choice == 7) {
			break;
		}
		switch(choice) {
		case 1:stackpush(s,1);break;
		case 2:popFromstack(s);break;
		case 3:GetTopofstack(s);break;
		case 4:sizeofstack(s);break;
		case 5:isEmptystack(s);break;
		case 6:Destroystack(s);
			break;
		default:printf("�����������������\n");
		}
	}
	system("pause");
	return 0;
}


