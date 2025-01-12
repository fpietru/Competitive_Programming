#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 1e5+15, INF = 1e9+7;
vector<pii> G[MxN];
vector<int> pre[MxN];
set<int> ans;
int dst[MxN];

void backtrack(int v, int p)
{
	ans.insert(v);
	for (auto u : pre[v])
		if (u != p)
			backtrack(u, v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}

	for (int i=1; i<=n; i++)
		dst[i] = INF;

	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.push({0, 1});
	dst[1] = 0;

	while (!Q.empty())
	{
		pii v = Q.top();
		Q.pop();

		if (v.FR != dst[v.SD])
			continue;

		for (auto p : G[v.SD])
		{
			if (v.FR + p.SD < dst[p.FR])
			{
				dst[p.FR] = v.FR + p.SD;
				pre[p.FR].clear();
				pre[p.FR].push_back(v.SD);
				Q.push({dst[p.FR], p.FR});
			}
			else if (v.FR + p.SD == dst[p.FR])
				pre[p.FR].push_back(v.SD);
		}
	}

	backtrack(n, n);

	for (auto p : ans)
		cout << p << "\n";
	
	return 0;
}