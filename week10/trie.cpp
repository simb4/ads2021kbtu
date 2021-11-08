#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int N = (int)1e5 + 7;

int vn = 1;
int to[N][26], cnt[N];
/*
	to[v][c] = id of the vertex by letter c transition
*/

void add(string s) {
	int v = 1;
	for (int i = 0; i < s.length(); i++) {
		// do transition by letter s[i]
		char c = s[i] - 'a';
		if (to[v][c] == 0) {
			// create vertex if no vertex
			to[v][c] = ++vn;
		}

		v = to[v][c]; // do transition

		cnt[v]++; // increasing counter in vertex
	}
}

int get(string s) {
	int v = 1;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i] - 'a';
		if (to[v][c] == 0) {
			return 0;
		}
		v = to[v][c];
	}
	return cnt[v];
}


int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		add(s);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		int ans = get(s);
		cout << "found " << ans << " completions for string " << s << "\n";
	}


	return 0;
}




