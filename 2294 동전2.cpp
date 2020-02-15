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

const int MAX = 987654321;
queue<int> q;
vector<int> v[100001];

int n, k;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) break;

		if (cur > 0) {
			v[cur].push_back(cur - 1);
			q.push(cur - 1);
		}

		if (cur < 100000) {
			v[cur].push_back(cur + 1);
			q.push(cur + 1);
		}

		if (cur <= 50000 && cur > 0) {
			v[cur].push_back(2 * cur);
			q.push(2 * cur);
		}
	}


	

	return 0;
}