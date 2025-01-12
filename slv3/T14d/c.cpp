#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
#define FR first
#define SD second

constexpr int MxN = 4e5+5;
constexpr ll INF = 1e18+7;
vector<pii> G[MxN];
ll d[MxN];
bool stacja[MxN];
int n, m, k, q;

void dijkstra(int st)
{
	for (int i=0; i<MxN; i++)
		d[i] = INF;
	
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	
	d[st] = 0;
	Q.push({0, st});
	
	while (!Q.empty())
	{
		ll dst = Q.top().FR;
		int v = Q.top().SD;
		Q.pop();
		
		if (dst != d[v])
			continue;
		
		for (auto e : G[v])
			if (d[e.FR] > d[v] + (ll)e.SD)
			{
				d[e.FR] = d[v] + (ll)e.SD;
				Q.push({d[e.FR], e.FR});
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k >> q;
	for (int i=1; i<=k; i++)
	{
		int x; cin >> x;
		stacja[x] = 1;
	}
	for (int i=1; i<=m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		G[a].push_back({b, w});
		G[b].push_back({a, w});
		G[a+n].push_back({b+n, w});
		G[b+n].push_back({a+n, w});
	}
	
	for (int i=1; i<=n; i++)
		if (stacja[i])
			G[i].push_back({i+n, 0});
	
	dijkstra(1);
	
	for (int i=1; i<=q; i++)
	{
		int x; cin >> x;
		cout << d[x+n] << "\n";
	}	
	
	return 0;
}
