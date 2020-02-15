#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int GO_MAX = 10; // 0부터 9까지

int t, n;

struct Trie {
	Trie* go[GO_MAX]; 
	bool output;
	bool goexist;

	Trie() {
		fill(go, go + GO_MAX, nullptr);
		output = false;
		goexist = false;
	}
	~Trie() {
		for (int i = 0; i < GO_MAX; i++) {
			if (go[i]) delete go[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0') output = true;
		else {
			int next = *key - '0';

			if (!go[next]) go[next] = new Trie;
			goexist = true;
			go[next]->insert(key + 1);
		}
	}
	bool consistent() {
		if (goexist && output) return false;

		for (int i = 0; i < GO_MAX; i++) {
			if (go[i] && !go[i]->consistent()) return false;
		}
		return true;
	}
};

int main()
{

	cin >> t;
	while (t--) {
		cin >> n;
		Trie* root = new Trie;
		bool res = true;
		for (int i = 0; i < n; i++) {
			char tel[11];
			scanf("%s", tel);
			root->insert(tel);
		}

		if (root->consistent()) cout << "YES\n";
		else cout << "NO\n";

		delete root;
	}

	return 0;
}