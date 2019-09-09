#define  _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;
//int main() {
//	vector<int>v1;
//	vector<int>v2(10, 5);
//	string s("hello");
//	//STL��[begin,end)
//	vector<char>v3(s.begin(), s.end());
//	vector<int>v4(v2);
//	int array[] = { 1,2,3,4,5,6 };
//	vector<int>v5(array, array + sizeof(array) / sizeof(array[0]));
//	vector<int>v6{ 1,2,3,4,5,6 };
//	for (size_t i = 0;i < v2.size();i++) {
//		cout << v2[i] << " ";
//	}
//	cout << endl;
//	//vector<char>::iterator it = v3.begin();  c++98
//	auto it = v3.begin();
//	while (it != v3.end()) {
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//	for (auto e : v5) {
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//int main() {
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	//resize �ı���ЧԪ�ظ�����sz���������Ԫ��ʹ��x������
//	//szС����ЧԪ�ظ�������vector����ЧԪ�ظ������ٵ�sz�����ײ������ռ䲻��
//	//sz������ЧԪ�ظ�����
//	//szС��capacity����vector���һ����ЧԪ�غ�׷�ӵ�sz�������������x���
//	//sz����capacity�����ݣ�Ȼ�������
//	v.resize(20, 8);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	v.resize(22, 9);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	v.resize(10,9);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	//reserve������  ע�⣺����ı���ЧԪ�ظ���  
//	//1��newcapacity<=oldcapacity��������
//	//2��newcapacity>oldcapacity,���ݣ������¿ռ䣬����Ԫ�أ��ͷžɿռ�
//
//	return 0;
//}

//������ʧЧ����������ָ��Ŀռ�Ƿ����ռ��Ѿ����ͷ�
//vector�е�����ʧЧ�ĳ�����
     //1�����п��ܵ��µײ�ռ�ı�Ĳ�����push_back   resize  reserve insert
     //2��erase��it����it������ʧЧ
//�����������ʹ�õ�����ǰ�������������¸�ֵ
#if 0
int main() {
	vector<int>v{ 1,2,3,4 };
	auto it = v.begin();
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	//it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}
#endif 

#if 0
int main() {
	vector<int>v{ 1,2,3,4 };
	auto it = v.begin();
	//v.clear();
	//v.erase(v.begin(), v.end());
	while (it != v.end()) {
		it=v.erase(it);
		it++;
	}
	return 0;
}
#endif

//int main(){
//	vector<vector<int>>generate(int numRows){
//		vector<vector<int>>vvRet;
//		vvRet.resize(numRows);
//		for (size_t i = 0;i < numRows;++i) {
//			vvRet[i].resize(i + 1);
//			vvRet[i][0] = 1;
//			vvRet[i][i] = 1;
//		}
//		for (int i = 2;i < numRows;++i) {
//			for (int j = 1;j < i;j++) {
//				vvRet[i][j] = vvRet[i - 1][j] + vvRet[i - 1][j - 1];
//			}
//		}
//		return vvRet;
//	}
//}


template<class T>
class vector {
public:
	typedef T* iterator;
public:
	vector();
	vector(size_t n, const T& data);
	template<class Iterator>
	vector(Iterator first, Iterator last);
	vector(const vector<T>& v);
	iterator begin() {
		return _start;
	}
	iterator end() {
		return _finish;
	}
	size_t size() {
		return _finish - _start;
	}
	size_t capacity() {
		return _endofstorage - _start;
	}
	bool Empty()const {
		return _start == _finish;
	}
	void resize(size_t newsize, const T& data = T()) {
		size_t oldsize = size();
		if (newsize <= oldsize) {
			_finish = _start + newsize;
		}
		else {
			size_t cap = capacity();
			if (newsize > cap) {
				reserve(newsize);
				for (size_t i = oldsize;i < newsize;i++) {
					*_finish++ = data;
				}
			}
		}
	}
	void reserve(size_t newcapacity) {
		size_t oldcapacity = capacity();
		if (newcapacity > oldcapacity) {
			T* ptemp = new T[newcapacity];
			if (_start) {
				size_t n = size();
				for (size_t i = 0;i < n;i++) 
					ptemp[i] = _start[i];
				delete[]_start;
				_start = ptemp;
				_finish = _start + n;
				_endofstorage = _start + newcapacity;
			}
		}
	}
	T& operator[](size_t index) {
		assert(index < size());
		return _start[index];
	}
	const T& operator[](size_t index)const {
		assert(index < size());
		return _start[index];
	}
	T& front() {
		return *_start;
	}
	const T& front()const {
		return *_start;
	}
	T& back() {
		return *(_finish - 1);
	}
	const T& back()const {
		return *(_finish - 1);
	}
	void push_back(const T&data) {
		if (size() == capacity()) {
			reserve(2 * capacity);
		}
		*_finish++ = data;
	}
	void Pop_back() {
		--_finish;
	}
	//void insert(iterator pos, const T& data)
	//{

	//}
	//iterator erase(iterator pos) {

	//}
	void clear() {
		_finish = _start;
	}
	
private:
	T* _start;
	T* _finish;
	T* _endofstorage;
};
int main() {
	return 0;
}

