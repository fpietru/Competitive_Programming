#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 2e6+12;
constexpr ll INF = 1e18+9;
vector<pii> G[MxN];
ll d[MxN];
int n, m;

void dijkstra(int st)
{
	for (int i=0; i<=2*n; i++)
		d[i] = INF;
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
	
	d[st] = 0LL;
	Q.push({0LL, st});
	
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

void dijkstra_dla_pelnych(int st)
{
	vector<bool> vis(2*n+1, 0);
	for (int i=0; i<=2*n; i++)
		d[i] = INF;

	d[st] = 0LL;
	for (int i=1; i<=2*n; i++)
	{
		int v = -1;
		for (int j=0; j<=2*n; j++)
			if (!vis[j] && (v == -1 || d[j] < d[v]))
				v = j;
		
		if (d[v] == INF)
			break;
		
		vis[v] = 1;	
		for (auto e : G[v])
			d[e.FR] = min(d[e.FR], d[v] + (ll)e.SD);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		G[a].push_back({b+n, w});
		G[b+n].push_back({a, w});
		G[b].push_back({a+n, w});
		G[a+n].push_back({b, w});
	}
	
	int st, ed; cin >> st >> ed;
	
	if (2*(ll)m == (ll)n*((ll)n-1))
		dijkstra_dla_pelnych(st);
	else
		dijkstra(st);
	
	if (d[ed] == INF) d[ed] = -1;
	if (d[ed+n] == INF) d[ed+n] = -1;
	
	cout << d[ed] << " " << d[ed+n] << "\n";

    return 0;
}
