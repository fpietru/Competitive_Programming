/*
	Zadanie "Drogi" z KI
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 1e4+4;
vector<int> G[MxN], tG[MxN];
set<int> DAG[MxN];
vector<int> order;
int comp[MxN], vis[MxN];
int in[MxN], out[MxN];
int n, m, c = 0;

void DFS(int v)
{
	vis[v] = 1;
	for (auto u : G[v])
		if (vis[u] != 1)
			DFS(u);
	order.push_back(v);
}

void SCC(int v, int c)
{
	comp[v] = c;
	for (auto u : tG[v])
	{
		if (!comp[u])
			SCC(u, c);
		if (c > comp[u])
			DAG[comp[u]].insert(c);
	}
}

void DFS2(int v)
{
	vis[v] = 2;
	for (auto u : DAG[v])
	{
		in[u]++;
		out[v]++;	
		if (vis[u] != 2)
			DFS2(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		tG[b].push_back(a);
	}

	for (int i=1; i<=n; i++)
		if (!vis[i])
			DFS(i);

	for (int i=order.size()-1; i>=0; i--)
		if (comp[order[i]] == 0)
			SCC(order[i], ++c);

	// for (int i=1; i<=c; i++)
	// {
	// 	cout << i << ": ";
	// 	for (auto a : DAG[i])
	// 		cout << a << " ";
	// 	cout << "\n";
	// }

	if (c != 1)
	{
		for (int i=1; i<=c; i++)
			if (vis[i] != 2)
				DFS2(i);

		int zeroin = 0, zeroout = 0;
		for (int i=1; i<=c; i++)
		{
			// cout << i << " [" << in[i] << " " << out[i] << "]\n"; 
			if (in[i] == 0) zeroin++;
			if (out[i] == 0) zeroout++;
		}

		cout << max(zeroin, zeroout) << "\n";
		// cout << "zeroin: " << zeroin << " zeroout:" << zeroout << "\n";	
	}
	else
		cout << "0\n";


	return 0;
}