#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

constexpr int MxN = 2e5+55;
vector<int> G[MxN];
int type[MxN];

void bfs(int a, int b)
{
	queue<pair<int, int>> qu;
	qu.push({a, b});
	type[a] = b;
	while (!qu.empty())
	{
		int v = qu.front().FR;
		int t = qu.front().SD;
		qu.pop();
		
		for (int u : G[v])
			if (type[u] == 0)
			{
				type[u] = (t%2)+1;
				qu.push({u, (t%2)+1});
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i=1; i<=n; i++)
	{
		if (G[i].size() == 0)
		{
			cout << "NIE\n";
			return 0;
		}

		if (type[i] == 0)
			bfs(i, 1);
	}

	cout << "TAK\n";
	for (int i=1; i<=n; i++)
		cout << (type[i] == 1 ? "K\n" : "S\n");
	
	return 0;
}