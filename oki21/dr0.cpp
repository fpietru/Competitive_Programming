/*
	Zadanie "Drogi Rowerowe" z XXV, etap II OI
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 5e4+4;
vector<int> G[MxN], tG[MxN];
set<int> DAG[MxN];
stack<int> st;
bool vis[MxN];
int comp[MxN];
ll ans[MxN], csize[MxN];
int n, m, c = 0;

void dfs1(int v)
{
	vis[v] = 1;
	for (auto u : G[v])
		if (vis[u] == 0)
			dfs1(u);
	st.push(v);
}

void dfs2(int v, int color)
{
	comp[v] = color;
	csize[color]++;

	for (auto u : tG[v])
	{
		if (comp[u] == 0)
			dfs2(u, color);
		if (color > comp[u])
			DAG[comp[u]].insert(color);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		tG[b].push_back(a);
	}

	for (int i=1; i<=n; i++)
		if (vis[i] == 0)	
			dfs1(i);

	while (!st.empty())
	{
		int v = st.top();
		st.pop();
		if (comp[v] == 0)
			dfs2(v, ++c);
	}

	for (int i=c; i>=1; i--)
	{
		for (auto u : DAG[i])
			ans[i] += ans[u];
		ans[i] += csize[i];
	}

	for (int i=1; i<=n; i++)
		cout << ans[comp[i]] - 1 << "\n";

	return 0;
}