#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
const int N = (int)1e5 + 7;
const int inf = (int)1e9;
int n, m;
int d[N], was[N], pr[N];
vector<pii> g[N];

int main() {

	int v0;
	scanf("%d %d %d", &n, &m, &v0);
	for (int i = 1; i <= m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	scanf("%d", &v0);
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[v0] = 0;

	for (int i = 1; i <= n; i++) {
		// find min d[v] vertex v
		int v = -1;
		for (int j = 1; j <= n; j++) {
			if (!was[j] && (v == -1 || d[v] > d[j]))
				v = j;
		}
		if (d[v] == inf)
			break;
		was[v] = 1;
		// do relaxation from vertex v
		for (auto [u, w] : g[v]) {
			if (d[v] + w < d[u]) {
				d[u] = d[v] + w;
				pr[u] = v;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << "d[" << i << "] = " << (d[i] == inf ? -1 : d[i]) << "\n";
	}

	return 0;
}













