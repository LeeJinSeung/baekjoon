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

string s, t;
int arr[10];
int sum;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - '0']++;
		sum += s[i] - '0';
	}

	if (sum % 3 == 0 && arr[0] > 0) {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < arr[i]; j++) {
				t.push_back(i + '0');
			}
		}
		cout << t;
	}
	else cout << -1;



	return 0;
}