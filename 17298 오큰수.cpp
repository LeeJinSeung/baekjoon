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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, x;
stack<int> st;
vector<int> v;
int arr[1000001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	st.push(1000001);

	for (int i = n - 1; i >= 0; i--) {
		while (st.top() <= v[i]) st.pop();

		if (st.top() >= 1000001) arr[i] = -1;
		else arr[i] = st.top();
		st.push(v[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}