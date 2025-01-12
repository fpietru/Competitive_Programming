/*
	Zadanie "Zdjęcia Krasnali" z XXVIII OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 5e5+15;
vector<int> G[MxN];
vector<int> nG[MxN];
int deg[MxN], deg_in[MxN];
bool vis[MxN], in_queue[MxN];
int ans[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	queue<int> Q;
	Q.push(1);
	in_queue[1] = 1;
	
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		
		vis[v] = 1;
		in_queue[v] = 0;
		
		for (auto u : G[v])
			if (!vis[u])
			{
				nG[v].push_back(u);
				deg_in[u]++;
				
				if (in_queue[u])
				{
					cout << "NIE\n";
					return 0;
				}
				
				if ((deg[u] >> 1) == deg_in[u] && u != 2)
				{ 
					Q.push(u);
					in_queue[u] = 1;
				}
			}
	}
	
	for (int i=1; i<=n; i++)
		if (vis[i] == 0 && G[i].size() != 0 && i != 2)
		{
			cout << "NIE\n";
			return 0;
		}
	
	/*
	for (int i=1; i<=n; i++)
	{
		cout << i << ": ";
		for (auto u : nG[i])
			cout << u << " ";
		cout << "\n";
	}*/
	
	
	// sortowanie topologiczne
	memset(deg, 0, sizeof(deg));
	
	for (int i=1; i<=n; i++)
		for (auto u : nG[i])
			deg[u]++;
	
	while (!Q.empty())
		Q.pop();
	vector<int> toposorted;
	
	for (int i=1; i<=n; i++)
		if (deg[i] == 0)
			Q.push(i);
	
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		
		toposorted.push_back(v);
		
		for (auto u : G[v])
		{
			deg[u]--;
			if (deg[u] == 0)
				Q.push(u);
		}
	}
	
	if (toposorted.size() != n)
	{
		cout << "NIE\n";
		return 0;
	}
	
	for (int i=0; i<(int)toposorted.size(); i++)
		ans[toposorted[i]] = i+1;
		
	cout << "TAK\n";
	for (int i=1; i<=n; i++)
		cout << ans[i] << " ";
	cout << "\n";


	return 0;
}
