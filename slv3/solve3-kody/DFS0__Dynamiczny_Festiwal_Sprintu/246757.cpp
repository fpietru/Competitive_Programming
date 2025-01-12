#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
vector<int> G[MxN];
int pre[MxN];
int post[MxN];
int gtimer = 0;

void dfs(int v, int p)
{
	pre[v] = ++gtimer;
	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
	post[v] = ++gtimer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<n; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i=1; i<=n; i++)
		sort(G[i].begin(), G[i].end());
	
	dfs(1, 1);
	
	for (int i=1; i<=n; i++)
		cout << pre[i] << " " << post[i] << "\n";

    return 0;
}
