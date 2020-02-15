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

struct Time {
	int start;
	int end;
	Time(int s, int e) {
		start = s;
		end = e;
	}
	bool operator <(const Time& t) {
		if (end == t.end) return start < t.start;
		else return end < t.end;
	}
};

int n, a, b, cur, cnt;
vector<Time> v;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(Time(a, b));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (cur <= v[i].start) {
			cur = v[i].end;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}