#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
const int N = (int)1e5 + 7;
const int inf = (int)1e9;
int n, m;
int d[N], pr[N];
vector<pii> g[N];

int main() {

	int v0;
	scanf("%d %d", &n, &m);
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

	priority_queue< pair<int,int> > pq;
	pq.push(make_pair(-0, v0));
	while (!pq.empty()) {
		auto [dv, v] = pq.top();
		pq.pop();

		// check if it is "actual-enough" value
		if (dv > d[v])
			continue;
		// do relaxation
		for (auto [u , w] : g[v])
			if (d[u] > d[v] + w)
			{
				d[u] = d[v] + w;
				pq.push(make_pair(-d[u], u));
				pr[u] = v;
			}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << "d[" << i << "] = " << (d[i] == inf ? -1 : d[i]) << "\n";
	}

	return 0;
}













