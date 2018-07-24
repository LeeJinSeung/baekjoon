#include <iostream>
using namespace std;

long long tsq[100];
long long cnt[100];

int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	tsq[0] = A % C;
	cnt[0] = 1;
	long long sq = A % C;
	long long pos = 1;
	long long count = 1;
	long long res = 1;
	while (2 * count <= B) {
		count = count * 2;
		sq = ((sq % C)*(sq % C)) % C;
		cnt[pos] = count;
		tsq[pos] = sq % C;
		pos++;
	}
	for (int i = pos - 1; i >= 0; --i) {
		if (B >= cnt[i]) {
			B = B - cnt[i];
			res = ((res % C) * (tsq[i] % C)) % C;
		}
		if (B == 0) {
			break;
		}
	}
	cout << res % C;
	system("pause >> null");
	return 0;
}
