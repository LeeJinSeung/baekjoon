#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 128;
int n, m, t, res;
char arr[21];

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
			int idx = *key - ' ';
			if (!next[idx]) next[idx] = new Trie();
			next[idx]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (*key == '\0' && finish) return true;
		int idx = *key - ' ';
		if (next[idx] == NULL) return false;
		return next[idx]->find(key + 1);
	}

	void check(const char* key) {
		if (*key == '\0') {
			return;
		}
		else {
			int idx = *key - ' ';
			if (next[idx]) {
				next[idx]->del = false;
				del = false;
			}
			else return;
			next[idx]->check(key + 1);
		}
	}

	void dfs() {
		if (del) {
			res++;
			return;
		}
		else if (finish) res++;
		for (int i = 0; i < MAX; i++) {
			if (next[i]) next[i]->dfs();
		}
	}

};

int main()
{
	cin >> t;
	while (t--) {
		Trie* root = new Trie();
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%s", arr);
			root->insert(arr);
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			scanf("%s", arr);
			root->check(arr);
		}
		root->dfs();
		cout << res << '\n';
		res = 0;
		delete root;
	}




	return 0;
}