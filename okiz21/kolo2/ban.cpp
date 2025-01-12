#include <bits/stdc++.h>
using namespace std;

const int MxN = 3e4+4;
vector<int> G[MxN];
int type[MxN];
bool vis[MxN];

void dfs(int v, int t)
{
	type[v] = t;
	for (int u : G[v])
		if (!vis[u])
		{
			vis[u] = 1;
			dfs(u, t);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int a; cin >> a;
		G[i].push_back(a);
	}

	int t = 0;
	for (int i=1; i<=n; i++)
		if (!vis[i])
			dfs(i, ++t);
	
	cout << t << "\n";

	return 0;
}