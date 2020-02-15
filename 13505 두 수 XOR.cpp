#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 2;
int n, x, res;
int arr[100001];
char c[33];

struct Trie {
	Trie* next[MAX];
	bool finish, del;

	Trie() : finish(false), del(true) {
		for (int i = 0; i < MAX; i++) next[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < MAX; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int idx = *key - '0';
			if (!next[idx]) next[idx] = new Trie();
			next[idx]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (*key == '\0' && finish) return true;
		int idx = *key - '0';
		if (next[idx] == NULL) return false;
		return next[idx]->find(key + 1);
	}

	void query(char* key) {
		if (*key == '\0') return;

		int idx = *key - '0';
		idx ^= 1;
		if (next[idx]) {
			*key = '1';
			next[idx]->query(key + 1);
		}
		else {
			*key = '0';
			next[idx ^ 1]->query(key + 1);
		}

	}

};

int main()
{
	Trie* root = new Trie();
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		x = arr[i];
		for (int j = 31; j >= 0; j--) {
			if (x % 2) c[j] = '1';
			else c[j] = '0';
			x /= 2;
		}
		c[32] = '\0';
		root->insert(c);
	}


	for (int i = 0; i < n; i++) {
		x = arr[i];
		for (int j = 31; j >= 0; j--) {
			if (x % 2) c[j] = '1';
			else c[j] = '0';
			x /= 2;
		}
		c[32] = '\0';
		root->query(c);
		int r = 0;
		for (int j = 31; j > -0; j--) {
			r += (c[j] - '0') * (1 << (31 - j));
		}
		res = max(res, r);

	}

	printf("%d", res);




	return 0;
}