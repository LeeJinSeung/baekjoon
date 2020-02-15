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

int n, m, k;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		if (n >= 2 * m) n--;
		else m--;
	}

	if (n >= 2 * m) cout << m;
	else cout << n / 2;




	return 0;
}