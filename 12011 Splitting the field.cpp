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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MAX = 1000000001;

int n;
pll cow[50000];
ll minX, maxX, minY, maxY, area;

// first min, second max
pll front[50000];
pll back[50000];
ll res;


bool cmp(pll &a, pll& b) {
	return a.second < b.second;
}



int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	minX = minY = MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cow[i].first >> cow[i].second;
		if (minX > cow[i].first) minX = cow[i].first;
		if (maxX < cow[i].first) maxX = cow[i].first;
		if (minY > cow[i].second) minY = cow[i].second;
		if (maxY < cow[i].second) maxY = cow[i].second;
	}

	area = (maxX - minX) * (maxY - minY);

	// x축 정렬
	sort(cow, cow + n);

	front[0].first = cow[0].second;
	front[0].second = cow[0].second;
	back[0].first = cow[n - 1].second;
	back[0].second = cow[n - 1].second;

	for (int i = 1; i < n; i++) {
		front[i].first = min(front[i - 1].first, cow[i].second);
		front[i].second = max(front[i - 1].second, cow[i].second);
		back[i].first = min(back[i - 1].first, cow[n - 1 - i].second);
		back[i].second = max(back[i - 1].second, cow[n - 1 - i].second);
	}



	for (int i = 1; i < n - 1; i++) {
		ll tmp = (cow[i].first - cow[0].first) * (front[i].second - front[i].first);
		ll tmp2 = (cow[n - 1].first - cow[i + 1].first) * (back[n - 2 - i].second - back[n - 2 - i].first);
		if (res < area - tmp - tmp2) res = area - tmp - tmp2;
	}


	// y축 정렬
	sort(cow, cow + n, cmp);

	front[0].first = cow[0].first;
	front[0].second = cow[0].first;
	back[0].first = cow[n - 1].first;
	back[0].second = cow[n - 1].first;

	for (int i = 1; i < n; i++) {
		front[i].first = min(front[i - 1].first, cow[i].first);
		front[i].second = max(front[i - 1].second, cow[i].first);
		back[i].first = min(back[i - 1].first, cow[n - 1 - i].first);
		back[i].second = max(back[i - 1].second, cow[n - 1 - i].first);
	}

	for (int i = 1; i < n - 1; i++) {
		ll tmp = (cow[i].second - cow[0].second) * (front[i].second - front[i].first);
		ll tmp2 = (cow[n - 1].second - cow[i + 1].second) * (back[n - 2 - i].second - back[n - 2 - i].first);
		if (res < area - tmp - tmp2) res = area - tmp - tmp2;
	}

	cout << res;


	return 0;
}