#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e6+6;
constexpr ll INF = 1e18+7;
vector<int> G[MxN];
int waga[MxN];
bool vis[MxN];
ll suma;

void dfs(int v)
{
	vis[v] = 1;
	suma += (ll)waga[v];
	for (auto u : G[v])
		if (!vis[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> waga[i];
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	ll ans = INF;
	for (int i=1; i<=n; i++)
		if (vis[i] == 0)
		{
			suma = 0LL;
			dfs(i);
			ans = min(ans, suma);
		}
			
	cout << ans << "\n";

    return 0;
}
