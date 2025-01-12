/*
	Zadanie "Głuchy telefon"
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e5+55;
vector<int> G[MxN];
int deg[MxN];
bool vis[MxN];

void dfs(int v)
{
	vis[v] = 1;
	for (int u : G[v])
		if (!vis[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		G[i].push_back(x);
		deg[x]++;
	}

	vector<int> st;
	for (int i=1; i<=n; i++)
		if (deg[i] == 0)
			st.push_back(i);
	
	int ans = 0;
	for (int v : st)
		if (!vis[v])
		{
			ans++;
			dfs(v);
		}

	for (int i=1; i<=n; i++)
		if (!vis[i])
		{
			ans++;
			dfs(i);
		}

	cout << ans << "\n";

	return 0;
}