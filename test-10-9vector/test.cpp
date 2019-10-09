#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//int main() {
//	vector<int>v1;
//	vector<int>v2(4, 100);
//	vector<int>v3(v2);
//	vector<int>v4(v3.begin(), v3.end());
//	int array[] = { 0,1,2,3,4,5 };
//	vector<int>v5(array, array + sizeof(array) / sizeof(array[0]));
//	vector<int>v6{ 1,2,3,4,5,6 };
//    //vector<int>::iterator it = second.begin();
//	auto it = v2.begin();
//	while (it != v2.end()) {
//		cout << *it<<" ";
//		it++;
//	}
//	cout << endl;
//	for (size_t i = 0;i < v3.size();i++) {
//		cout << v3[i]<<" ";
//	}
//	cout << endl;
//	for (auto e : v5) {
//		cout << e<<" ";
//	}
//	cout << endl;
//	return 0;
//}

#if 0
int main() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//vector<int>::iterator it = v.begin();
	auto it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	auto i = v.begin();
	while (i != v.end()) {
		*i *= 2;
		cout << *i << " ";
		i++;
	}
	cout << endl;
	auto ret = v.rbegin();
	while (ret != v.rend()) {
		cout << *ret << " ";
		ret++;
	}
	cout << endl;
	return 0;
}
#endif


int main() {
	vector<int>v;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(8, 0);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(100, 9);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(50,9);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(2);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	//resize �ı���ЧԪ�ظ�����sz���������Ԫ��ʹ��x������
	//szС����ЧԪ�ظ���������ЧԪ�ظ������ٵ�sz���ײ������ռ䲻��
	//sz������ЧԪ�ظ�����
	//szС��capacity,����ЧԪ�����ӵ�sz���������Ԫ����x������
	//sz����capacity�����ݣ�Ȼ�������
	return 0;
}


#if 0
int main() {
	vector<int>v;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << endl;      //4
	cout << v.capacity() << endl;   //4
	v.reserve(10);
	cout << v.size() << endl;    //4
	cout << v.capacity() << endl;//10
	v.reserve(50);
	cout << v.size() << endl;     //4
	cout << v.capacity() << endl;  //50
	v.reserve(30);
	cout << v.size() << endl;    //4
	cout << v.capacity() << endl;//50
	v.reserve(2);
	cout << v.size() << endl;    //4
	cout << v.capacity() << endl;//50
	//reserve :����  ע�⣺����ı���ЧԪ�ظ���
	//nwecapacity<=oldcapacity  ��������κβ���
	//nwecapacity>oldcapacity  ���ݣ������¿ռ�  ����Ԫ��  �ͷžɿռ�
	return 0;
}
#endif