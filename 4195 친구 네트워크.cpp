#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <stack>
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, f, cnt;
string a, b;
int arr[200001];
int posA, posB;

int find(int n) {
	if (arr[n] < 0) return n;
	return arr[n] = find(arr[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	arr[a] += arr[b];
	arr[b] = a;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> f;
		unordered_map<string, int> m;
		memset(arr, -1, sizeof(arr));
		cnt = 0;

		for (int i = 0; i < f; i++) {
			cin >> a >> b;

			if (m.find(a) == m.end()) {
				m.insert({ a,cnt++ });
				posA = cnt - 1;
			}
			else posA = m[a];


			if (m.find(b) == m.end()) {
				m.insert({ b,cnt++ });
				posB = cnt - 1;
			}
			else posB = m[b];

			merge(posA, posB);


			cout << abs(arr[find(posA)]) << '\n';
		}
	}





	return 0;
}