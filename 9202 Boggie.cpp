#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 26;
int w, b;
char c;
string map[4];
bool visit[4][4];
int score[9] = { 0,0,0,1,1,2,3,5,11 };
int dr[8] = { 0,0,-1,-1,-1,1,1,1 };
int dc[8] = { -1,1,-1,0,1,-1,0,1 };
set<string> res;

struct Trie {
	Trie* next[MAX];
	bool finish;

	Trie() {
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
			int idx = *key - 'A';
			if (!next[idx]) next[idx] = new Trie();
			next[idx]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (*key == '\0' && finish) return true;
		int idx = *key - 'A';
		if (next[idx] == NULL) return false;
		return next[idx]->find(key + 1);
	}

	void func(int r, int c, string cur) {
		if (r < 0 || c < 0 || r >= 4 || c >= 4) return;
		if (visit[r][c]) return;
		if (cur.size() >= 8) return;

		visit[r][c] = true;
		cur = cur + map[r][c];
		if (next[map[r][c] - 'A'] == NULL) {
			visit[r][c] = false;
			return;
		}
		if (next[map[r][c] - 'A']->finish == true)
			res.insert(cur);

		for (int i = 0; i < 8; i++) {
			next[map[r][c] - 'A']->func(r + dr[i], c + dc[i], cur);
		}
		visit[r][c] = false;
	}
};

int main()
{
	Trie* root = new Trie();
	cin >> w;
	for (int i = 0; i < w; i++) {
		char arr[9];
		scanf("%s", arr);
		root->insert(arr);
	}

	cin >> b;
	for (int i = 0; i < b; i++) {
		string s = "";
		int total = 0;
		for (int j = 0; j < 4; j++) {
			cin >> map[j];
		}
		res.clear();
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				root->func(j, k, "");
			}
		}
		for (auto it : res) {
			total += score[it.size()];
			if (it.size() > s.size()) {
				s = it;
			}
		}
		cout << total << " " << s << " " << res.size() << '\n';

	}


	return 0;
}