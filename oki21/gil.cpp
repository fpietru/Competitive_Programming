/*
	Zadanie "Gildie" z XVII OI
*/
#include <bits/stdc++.h>
using namespace std;

const int Mxn = 2e5+3;
vector<int> G[Mxn];
char k[Mxn];

void DFS(int v)
{
	for (auto w : G[v])
	{
		if (k[w] != 'N') continue;
		if (k[v] == 'S') k[w] = 'K';
		else k[w] = 'S';
		DFS(w);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i=1; i<=n; i++) k[i] = 'N';

	for (int i=1; i<=n; i++)
	{
		if (G[i].size() == 0)
		{
			cout<<"NIE\n";
			return 0;
		}
		if (k[i] != 'N') continue;
		DFS(i);
	}

	cout<<"TAK\n";
	for (int i=1; i<=n; i++)
		cout<<k[i]<<"\n";

	return 0;
}