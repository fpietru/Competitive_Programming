#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
vector<int> G[MxN];
bool vis[MxN];

void dfs(int v)
{
	vis[v] = 1;
	for (auto u : G[v])
		if (vis[u] == 0)
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		G[i].push_back(x);
	}
	int ans = 0;
	for (int i=1; i<=n; i++)
		if (vis[i] == 0)
		{
			ans++;
			dfs(i);
		}
	cout << ans << "\n";

    return 0;
}
