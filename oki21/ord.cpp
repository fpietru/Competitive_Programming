/*
	Zadanie "Order Order" z OKI
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 5e5+15;
vector<int> G[MxN];
bool vis[MxN];
int pre[MxN];
int post[MxN];
int n, q, p = 1;

void DFS(int v)
{
	pre[v] = p++;
	vis[v] = 1;
	
	for (auto u : G[v])
		if (!vis[u])
			DFS(u);
	
	post[v] = p++; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int s;
	cin >> n >> q;
	for (int a=1; a<=n; a++)
	{
		int b; cin >> b; 
		G[b].push_back(a);
		G[a].push_back(b);
	}

	DFS(0);

	// for (int i=0; i<=n; i++)
		// printf("%d: [%d, %d]\n", i, pre[i], post[i]);

	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << ((pre[a] < pre[b] && post[a] > post[b]) ? "NIE\n" : "TAK\n");
	}

	return 0;
}