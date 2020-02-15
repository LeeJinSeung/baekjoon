#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

int adj[500001];
int n, u, v, leaf;
double w;


int main() {
	std::ios::sync_with_stdio(false);	cin.tie(0); cout.tie(0);

	cin >> n >> w;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u]++;
		adj[v]++;
	}

	for (int i = 2; i < 500001; i++) {
		if (adj[i] == 1) leaf++;
	}
	printf("%.10lf", w / leaf);


	return 0;
}