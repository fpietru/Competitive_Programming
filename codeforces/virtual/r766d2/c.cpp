#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 1e5+5;
vector<pii> G[MxN+10];
int res[MxN];

void dfs(int v, int p, int c)
{
	for (auto u : G[v])
		if (u.FR != p)
		{
			res[u.SD] = c;
			c ^= 1;
			dfs(u.FR, v, c);
		}
}

void solve()
{
	for (int i=1; i<=MxN; i++)
		G[i].clear();	
	memset(res, 0, sizeof(res));

	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back({b, i});
		G[b].push_back({a, i});
	}
	
	for (int i=1; i<=n; i++)
		if (G[i].size() > 2)
		{
			cout << "-1\n";
			return;
		}
	
	dfs(1, -1, 1);
	
	for (int i=1; i<=n-1; i++)
		cout << (res[i] == 1 ? "2 " : "5 ");
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}
