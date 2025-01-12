/*
	Zadanie "Sabotaż" z XXIV OI, etap I
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 5e5+55;
vector<int> G[MxN];
int SZ[MxN];
double dp[MxN];

void dfs(int v, int p)
{
	SZ[v] = 1;
	for (int u : G[v])
		if (u != p)
		{
			dfs(u, v);
			SZ[v] += SZ[u];
		}

	dp[v] = 0;
	for (int u : G[v])
		if (u != p)
			dp[v] = max(dp[v], min(dp[u], (double)SZ[u] / (double)(SZ[v]-1)));

	if (SZ[v] == 1)
		dp[v] = 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i=2; i<=n; i++)
	{
		int x; cin >> x;
		G[i].push_back(x);
		G[x].push_back(i);
	}

	dfs(1, 1);

	double ans = 0;
	for (int i=1; i<=n; i++)
		if (SZ[i] > k)
			ans = max(ans, dp[i]);

	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}