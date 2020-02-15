#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int MAX = 26;
int n, sum;

struct Trie {
	int cnt;
	Trie* next[MAX];
	bool finish;

	Trie() {
		for (int i = 0; i < MAX; i++) next[i] = NULL;
		cnt = 0;
	}
	~Trie() {
		for (int i = 0; i < MAX; i++)
			if ((next[i])) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int idx = *key - 'a';
			if (!next[idx]) next[idx] = new Trie();

			next[idx]->cnt++;
			next[idx]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (*key == '\0' && finish) return true;
		int idx = *key - 'a';
		if (next[idx] == NULL) return false;
		return next[idx]->find(key + 1);
	}

	void cal(Trie* tmp) {
		for (int i = 0; i < MAX; i++) {
			if (tmp->next[i] != NULL) {
				if (tmp->cnt != tmp->next[i]->cnt) {
					sum += tmp->next[i]->cnt;
				}
				cal(tmp->next[i]);
			}
		}
	}
};

int main()
{
	while (~scanf("%d", &n)) {
		Trie* root = new Trie;
		for (int i = 0; i < n; i++) {
			char arr[81];
			scanf("%s", arr);
			root->insert(arr);
		}
		root->cal(root);
		printf("%.2lf\n", sum * 1.0 / n);

		delete root;
		sum = 0;

	}

	return 0;
}