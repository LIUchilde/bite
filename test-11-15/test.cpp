#include<iostream>
using namespace std;
#if 0
int step(int m, int n) {
	if (m == 0 || n == 0) {
		return 1;
	}
	return step(m - 1, n) + step(m, n - 1);
}
int main() {
	int m, n;
	cin >> m >> n;
	cout << step(m, n) << endl;
	return 0;
}
#endif

#if 0
int Add(int A, int B) {
	int a = A;
	int b = B;
	if ((A & B)!=0) {
		A = (a & b) << 1;
		B = a ^ b;
	}
	return A ^ B;
}
int main() {
	int A, B;
	cin >> A >> B;
	cout<<Add(A, B)<<endl;
	return 0;
}
#endif
