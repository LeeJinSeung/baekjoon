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


stack<double> st;
int n;
string s;
double arr[26];
char str[101];

void calc(char op) {
	double n2 = st.top(); st.pop();
	double n1 = st.top(); st.pop();

	if (op == '+') st.push(n1 + n2);
	else if (op == '-') st.push(n1 - n2);
	else if (op == '*') st.push(n1* n2);
	else if (op == '/') st.push(n1 / n2);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cout << fixed;
	cout.precision(2);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') st.push(arr[s[i] - 'A']);
		else calc(s[i]);
	}
	cout << st.top();



	return 0;
}