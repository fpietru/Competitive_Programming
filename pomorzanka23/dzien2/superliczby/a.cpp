#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 1e5+5;
constexpr int base = (1<<17);
int Tree[2*base];
bool vis[MxN];
vector<int> warstwa[MxN];
vector<int> G[MxN];

void update(int v, int x) {
	v += base;
	Tree[v] = x;
	while (v) {
		v >>= 1;
		Tree[v] = max(Tree[2*v], Tree[2*v+1]);
	}
}

int query(int a, int b) {
	int res = 0;
	a += base - 1;
	b += base + 1;
	while ((a>>1) != (b>>1)) {
		if ((a&1) == 0) res = max(res, Tree[a+1]);
		if ((b&1) == 1) res = max(res, Tree[b-1]);
		a >>= 1; b >>= 1;
	}
	return res;
}

void dfs(int v) {
	vis[v] = true;
	for (auto u : G[v])
		if (!vis[u])
			dfs(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		int mx = query(1, x-1);
		if (mx > 0) {
			for (auto u : warstwa[mx])
				if (u < x) G[x].PB(u);
		}
		update(x, mx + 1);
		warstwa[mx+1].PB(x);
	}
	
	int mx = query(1, n);
	for (auto v : warstwa[mx])
		if (!vis[v])
			dfs(v);

	vector<int> ans;
	for (int i=1; i<=n; i++)
		if (vis[i]) ans.PB(i);
	
	cout << ans.size() << "\n";
	for (auto it : ans)
		cout << it << " ";
	cout << "\n";
	
	// ld mem = (ld)(sizeof(Tree) + sizeof(vis) + sizeof(ans) + sizeof(warstwa) + sizeof(G)) / (ld)(1<<20);
	// cout << "pamiec = " << mem << "\n";
	
	return 0;
}
