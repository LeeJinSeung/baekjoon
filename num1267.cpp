#include <iostream>
using namespace std;

int main() {
	int N, call;
	int y_Price = 0, m_Price = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> call;
		y_Price += ((call / 30) + 1) * 10;
		m_Price += ((call / 60) + 1) * 15;
	}
	if (y_Price < m_Price) {
		cout << "Y " << y_Price;
	}
	else if (y_Price == m_Price) {
		cout << "Y M " << y_Price;
	}
	else {
		cout << "M " << m_Price;
	}
	system("pause >> null");
	return 0;
}
