#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 26;

int n, m, cnt;

struct Trie {
	bool finish;
	Trie* next[MAX];

	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < MAX; i++)
			if ((next[i])) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') finish = true;
		else {
			int idx = *key - 'a';
			if (next[idx] == NULL) next[idx] = new Trie();
			next[idx]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0' && finish) return true;
		int idx = *key - 'a';
		if (next[idx] == NULL) return false;
		return next[idx]->find(key + 1);
	}
};

int main()
{


	cin >> n >> m;
	Trie* root = new Trie;
	string s;
	for (int i = 0; i < n; i++) {
		char arr[501];
		scanf("%s", arr);
		root->insert(arr);
	}

	for (int i = 0; i < m; i++) {
		char arr[501];
		scanf("%s", arr);
		if (root->find(arr)) cnt++;
	}


	cout << cnt;


	return 0;
}