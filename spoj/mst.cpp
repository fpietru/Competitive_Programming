/*
	Minimalne drzewo rozpinające
*/
#include <bits/stdc++.h>
using namespace std;

struct edge { int a, b, w; };
struct node { int p, s; };
constexpr int MxM = 1e5+55, MxN = 1e4+44;
edge edges[MxM];
node nodes[MxN];

void init(int v)
{
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getL(int v)
{
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b)
{
	a = getL(a), b = getL(b);
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[b].p = a;
	nodes[a].s += nodes[b].s;
}

bool cmp(edge A, edge B)
{
	return A.w < B.w;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}

	sort(edges, edges+m, cmp);

	for (int i=1; i<=n; i++)
		init(i);

	int ans = 0;
	for (int i=0; i<m; i++)
	{
		int v = edges[i].a;
		int u = edges[i].b;
		if (getL(v) != getL(u))
		{
			join(v, u);
			ans += edges[i].w;
		}
	}

	cout << ans << "\n";
	
	return 0;
}